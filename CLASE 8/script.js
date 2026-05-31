// Esperamos a que la página cargue completamente (buena práctica del profe!)
window.addEventListener('load', function() {

    // 1. Seleccionamos los elementos del FORMULARIO (los inputs)
    const inputNombre = document.querySelector('#nombre');
    const inputProfesion = document.querySelector('#profesion');
    const inputUrlImagen = document.querySelector('#url-imagen');
    const inputColor = document.querySelector('#color-fondo');
    const btnGenerar = document.querySelector('#btn-generar');

    // 2. Seleccionamos los elementos de la VISTA PREVIA (donde mostramos los datos)
    const perfilNombre = document.querySelector('#perfil-nombre');
    const perfilProfesion = document.querySelector('#perfil-profesion');
    const perfilImagen = document.querySelector('#perfil-imagen');
    const perfilContenedor = document.querySelector('#perfil-contenedor');

    // 3. Escuchamos el evento click del botón "Generar Perfil"
    btnGenerar.addEventListener('click', function() {

        // --- Actualizamos los TEXTOS ---
        // Tomamos el 'value' del input y lo ponemos en el 'innerText' del perfil
        perfilNombre.innerText = inputNombre.value;
        perfilProfesion.innerText = inputProfesion.value;

        // --- Actualizamos la IMAGEN ---
        // Cambiamos el atributo 'src' de la imagen de perfil
        if (inputUrlImagen.value) {
            perfilImagen.src = inputUrlImagen.value;
        }

        // --- Actualizamos el COLOR DE FONDO ---
        // Modificamos directamente el estilo 'backgroundColor' del contenedor
        perfilContenedor.style.backgroundColor = inputColor.value;

    });

});