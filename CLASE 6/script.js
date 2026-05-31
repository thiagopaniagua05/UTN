let texto = document.getElementById("texto");
let button = document.getElementById("button");

button.addEventListener('click', function(){
    texto.classList.toggle('estilos-texto');
    button.classList.toggle('estilos-button');
});