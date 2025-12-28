let chart = null;

// Panggil backend -> jalankan C++
async function searchProduct() {
    const target = document.getElementById("target").value;
    const algo = document.getElementById("algo").value;

    if (!target) {
        alert("Masukkan ID produk!");
        return;
    }

    try {
        const res = await fetch("/search", {
            method: "POST",
            headers: { "Content-Type": "application/json" },
            body: JSON.stringify({ target: target })
        });

        const data = await res.json();
        const result = data[algo];

        document.getElementById("resIndex").textContent = result.index;
        document.getElementById("resSteps").textContent = result.steps;
        document.getElementById("resTime").textContent = result.time + " ms";
    } catch (err) {
        alert("Gagal mengambil hasil dari C++");
        console.error(err);
    }
}

// Benchmark sederhana (pakai hasil simulasi)
function runBenchmark() {
    const sizes = [10, 100, 1000, 10000, 50000, 100000];
    const iterTimes = [];
    const recTimes = [];

    sizes.forEach(n => {
        iterTimes.push((Math.random() * 0.05 + 0.01).toFixed(4));
        recTimes.push((Math.random() * 0.07 + 0.02).toFixed(4));
    });

    const ctx = document.getElementById("chart").getContext("2d");
    if (chart) chart.destroy();

    chart = new Chart(ctx, {
        type: "line",
        data: {
            labels: sizes,
            datasets: [
                { label: "Iteratif (ms)", data: iterTimes, borderColor: "blue", fill: false },
                { label: "Rekursif (ms)", data: recTimes, borderColor: "red", fill: false }
            ]
        },
        options: {
            responsive: true,
            scales: {
                x: { title: { display: true, text: "Ukuran Data (N)" } },
                y: { title: { display: true, text: "Waktu (ms)" } }
            }
        }
    });
}
