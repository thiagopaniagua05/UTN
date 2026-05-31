window.addEventListener('load', function() {


    const inputNombre = document.querySelector('#nombre');
    const inputProfesion = document.querySelector('#profesion');
    const inputUrlImagen = document.querySelector('#url-imagen');
    const inputColor = document.querySelector('#color-fondo');
    const botonGenerar = document.querySelector('#boton-generar');

    const perfilNombre = document.querySelector('#perfil-nombre');
    const perfilProfesion = document.querySelector('#perfil-profesion');
    const perfilImagen = document.querySelector('#perfil-imagen');
    const perfilFondo = document.querySelector('#perfil-fondo');

    botonGenerar.addEventListener('click', function(){

        perfilNombre.innerText = inputNombre.value;
        perfilProfesion.innerText = inputProfesion.value;
        perfilImagen.src = inputUrlImagen.value;
        perfilFondo.style.backgroundColor = inputColor.value;
        
    });

});