window.addEventListener('load', function () {
    const nombre = document.getElementById('nombre');
    const apellido = document.getElementById('apellido');
    const email = document.getElementById('email');
    const plan = document.getElementById('plan');

    const cliente = document.getElementById('res-cliente');
    const emailc = document.getElementById('res-email');
    const planc = document.getElementById('res-plan');

    const formulario = document.getElementById('formulario-plan');
    const card = document.getElementById('card-confirmacion');

    // 3. Escuchamos el SUBMIT del formulario (No el click del botón)
    formulario.addEventListener('submit', function (event) {
    
        event.preventDefault();
   
        const nombreCompleto = nombre.value + " " + apellido.value;
     
        cliente.innerText = nombreCompleto;
        emailc.innerText = email.value;
        planc.innerText = plan.value;

        formulario.classList.toggle('oculto'); 
        card.classList.toggle('oculto');  
    });
    
});