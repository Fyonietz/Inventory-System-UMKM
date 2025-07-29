function time(){
     setInterval(() => {
  fetch("time")
    .then((res) => res.text())
    .then((time) => {
      document.getElementById("time").textContent = time;
    })
    .catch((e) => {
      console.error("Time fetch error:", e);
    });
}, 1000);
}

time();