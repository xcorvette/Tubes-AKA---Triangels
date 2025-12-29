const express = require("express");
const { exec } = require("child_process");
const path = require("path");

const app = express();

app.use(express.json());
app.use(express.static(path.join(__dirname, "public")));

const binPath = path.join(__dirname, "cpp", "binary");

// 🔍 Endpoint search
app.post("/search", (req, res) => {
  const { target } = req.body;

  if (target === undefined) {
    return res.status(400).json({ error: "Target tidak boleh kosong" });
  }

  exec(`echo ${target} | "${binPath}"`, (err, stdout, stderr) => {
    if (err) {
      console.error("C++ error:", stderr || err);
      return res.status(500).json({ error: "Gagal menjalankan program C++" });
    }

    try {
      const json = JSON.parse(stdout.trim());
      res.json(json);
    } catch (e) {
      console.error("Output search:", stdout);
      res.status(500).json({ error: "Output C++ bukan JSON valid" });
    }
  });
});

// 📊 Endpoint benchmark
app.get("/benchmark", (req, res) => {
    exec(`echo -1 | "${binPath}"`, (err, stdout, stderr) => {
      if (err) {
        console.error(stderr || err);
        return res.status(500).json({ error: "Gagal menjalankan benchmark" });
      }
  
      try {
        const json = JSON.parse(stdout.trim());
        res.json(json);   // ⬅️ langsung kirim array
      } catch (e) {
        console.error("Output:", stdout);
        res.status(500).json({ error: "Output benchmark bukan JSON valid" });
      }
    });
  });
  

const PORT = process.env.PORT || 3000;
app.listen(PORT, () => {
  console.log(`✅ Server jalan di port ${PORT}`);
});
