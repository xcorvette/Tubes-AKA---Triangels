let chart = null;

// Dummy handler cari (sementara, nanti ganti dari C++)
function searchProduct() {
    const target = document.getElementById("target").value;
    const algo = document.getElementById("algo").value;

    if (target === "") {
        alert("Masukkan ID produk!");
        return;
    }

    // Dummy hasil (nanti dari C++)
    const result = {
        index: Math.floor(Math.random() * 100),
        steps: Math.floor(Math.random() * 20) + 1,
        time: (Math.random() * 0.1).toFixed(6)
    };

    document.getElementById("resIndex").textContent = result.index;
    document.getElementById("resSteps").textContent = result.steps;
    document.getElementById("resTime").textContent = result.time + " ms";
}

// Benchmark dummy + grafik
function runBenchmark() {
    const sizes = [10, 100, 1000, 10000, 50000, 100000];
    let iterTimes = [];
    let recTimes = [];

    sizes.forEach(n => {
        iterTimes.push((Math.random() * 0.1).toFixed(4));
        recTimes.push((Math.random() * 0.15).toFixed(4));
    });

    const ctx = document.getElementById("chart").getContext("2d");
    if (chart) chart.destroy();

    chart = new Chart(ctx, {
        type: "line",
        data: {
            labels: sizes,
            datasets: [
                {
                    label: "Iteratif (ms)",
                    data: iterTimes,
                    borderColor: "blue",
                    fill: false
                },
                {
                    label: "Rekursif (ms)",
                    data: recTimes,
                    borderColor: "red",
                    fill: false
                }
            ]
        },
        options: {
            responsive: true,
            scales: {
                x: {
                    title: {
                        display: true,
                        text: "Ukuran Data (N)"
                    }
                },
                y: {
                    title: {
                        display: true,
                        text: "Waktu (ms)"
                    }
                }
            }
        }
    });
}
