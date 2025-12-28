const express = require("express");
const { exec } = require("child_process");
const path = require("path");

const app = express();
app.use(express.json());
app.use(express.static("public"));

app.post("/search", (req, res) => {
    const target = req.body.target;

    const exePath = path.join(__dirname, "cpp", "binary.exe");

    exec(`echo ${target} | "${exePath}"`, (err, stdout, stderr) => {
        if (err) {
            console.error(err);
            return res.status(500).json({ error: "Gagal menjalankan program C++" });
        }

        try {
            const data = JSON.parse(stdout.trim());
            res.json(data);
        } catch (e) {
            console.error("Output C++:", stdout);
            res.status(500).json({ error: "Output C++ bukan JSON valid" });
        }
    });
});

const PORT = 3000;
app.listen(PORT, () => {
    console.log(`Server jalan di http://localhost:${PORT}`);
});
