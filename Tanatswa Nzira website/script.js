const menuIcon = document.querySelector("#menu-icon");
const navLinks = document.querySelector(".nav-links");

menuIcon.onclick = () => {
    navLinks.classList.toggle("active");
};

/* CLOSE MENU WHEN LINK IS CLICKED */
document.querySelectorAll(".nav-links a").forEach(link => {
    link.onclick = () => {
        navLinks.classList.remove("active");
    };
});