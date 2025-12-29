const express = require("express");
const { exec } = require("child_process");
const path = require("path");

const app = express();
app.use(express.json());
app.use(express.static("public"));

app.post("/search", (req, res) => {
  const target = req.body.target;
  const exePath = path.join(__dirname, "cpp", "binary.exe");

  exec(`echo ${target} | "${exePath}"`, (err, stdout) => {
    if (err) {
      console.error(err);
      return res.status(500).json({ error: "Gagal menjalankan C++" });
    }
    try {
      res.json(JSON.parse(stdout.trim()));
    } catch {
      res.status(500).json({ error: "Output bukan JSON" });
    }
  });
});

// ⬇️ INI YANG PENTING
const PORT = process.env.PORT || 3000;
app.listen(PORT, () => {
  console.log("Server jalan di port", PORT);
});
