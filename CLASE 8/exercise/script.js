window.addEventListener('load', function(){
    // 1. CAPTURA DE INPUTS
    const inputTitulo = document.querySelector('#titulo');
    const inputDescripcion = document.querySelector('#descripcion');
    const inputUrlImagen = document.querySelector('#url-imagen');
    const inputSeccion = document.querySelector('#selector'); // Usaremos este nombre
    const botonGenerar = document.querySelector('#boton-generar');

    // 2. ELEMENTOS DE LA CARD
    const seccionTitulo = document.querySelector('#seccion-nombre');
    const seccionDescripcion = document.querySelector('#seccion-descripcion');
    const seccionImagen = document.querySelector('#imagen');
    const nombreSeccionDisplay = document.querySelector('.div-seccion h2');
    const seccionFondo = document.querySelector('#seccion-fondo'); // Agregamos esta que faltaba

    botonGenerar.addEventListener('click', function(){

        seccionTitulo.innerText = inputTitulo.value;
        seccionDescripcion.innerText = inputDescripcion.value;
        seccionImagen.src = inputUrlImagen.value;  
        
        // Usamos inputSeccion que es como la llamaste arriba
        nombreSeccionDisplay.innerText = inputSeccion.value;    

        // Lógica de colores
        if (inputSeccion.value === "Noticias") {
            seccionFondo.style.backgroundColor = "red";
        }
        else if (inputSeccion.value === "Deportes") {
            seccionFondo.style.backgroundColor = "green";
        }
        else if (inputSeccion.value === "Gaming"){
            seccionFondo.style.backgroundColor = "violet";
        }
    });
})