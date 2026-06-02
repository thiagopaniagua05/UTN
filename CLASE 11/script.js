const productos = [
    { nombre: "Agua Mineral 5L", precio: 1200, stock: 15 },
    { nombre: "Agua con Gas 2L", precio: 800, stock: 0 },
    { nombre: "Soda en Sifón", precio: 950, stock: 24 },
    { nombre: "Soda en lata", precio: 1950, stock: 4 },
    { nombre: "Soda en vino", precio: 950, stock: 0 },
    { nombre: "Coca Cola 50ml", precio: 2950, stock: 61 }
];

window.addEventListener('load', function() {

    const buscador = document.getElementById('buscador');
    const boton = document.getElementById('btn-buscar');
    const listaDiv = document.getElementById('lista-productos');

    boton.addEventListener('click', function() {
        
        listaDiv.innerHTML = "";
        const textoBuscado = buscador.value.toLowerCase();

        productos.forEach(function(producto) {
            
            const nombreProducto = producto.nombre.toLowerCase();

            if (nombreProducto.includes(textoBuscado) && producto.stock > 0) {
                
                listaDiv.innerHTML += `
                    <div class="producto-item">
                        <p><strong>${producto.nombre}</strong> - $${producto.precio}</p>
                        <p>Stock disponible: ${producto.stock} unidades</p>
                        <hr>
                    </div>
                `;
            }
        });

        // Opcional: ¿Qué pasa si recorrió todo y no encontró nada?
        if (listaDiv.innerHTML === "") {
            listaDiv.innerHTML = "<p>No se encontraron productos con stock disponible.</p>";
        }
    });

});