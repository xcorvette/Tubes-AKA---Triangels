const express = require("express");
const { exec } = require("child_process");
const path = require("path");

const app = express();
app.use(express.json());
app.use(express.static("public"));

app.post("/search", (req, res) => {
  const target = req.body.target;

  const binPath = path.join(__dirname, "cpp", "binary"); // tanpa .exe

  exec(`echo ${target} | ${binPath}`, (err, stdout, stderr) => {
    if (err) {
      console.error(stderr || err);
      return res.status(500).json({ error: "Gagal menjalankan C++" });
    }

    try {
      res.json(JSON.parse(stdout.trim()));
    } catch (e) {
      console.error("Output:", stdout);
      res.status(500).json({ error: "Output bukan JSON" });
    }
  });
});

const PORT = process.env.PORT || 3000;
app.listen(PORT, () => {
  console.log("Server jalan di port", PORT);
});
