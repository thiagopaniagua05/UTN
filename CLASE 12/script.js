const productos = [
    { nombre: "Agua Mineral 5L", precio: 1200, stock: 15, imagen: "https://images.unsplash.com/photo-1560343090-f0409e92791a?q=80&w=400" },
    { nombre: "Agua con Gas 2L", precio: 800, stock: 0, imagen: "https://images.unsplash.com/photo-1560343090-f0409e92791a?q=80&w=400" },
    { nombre: "Soda en Sifón", precio: 950, stock: 24, imagen: "https://images.unsplash.com/photo-1523362628745-0c100150b504?q=80&w=400" },
    { nombre: "Soda en lata", precio: 1950, stock: 4, imagen: "https://images.unsplash.com/photo-1523362628745-0c100150b504?q=80&w=400" },
    { nombre: "Soda en vino", precio: 950, stock: 0, imagen: "https://images.unsplash.com/photo-1560343090-f0409e92791a?q=80&w=400" },
    { nombre: "Coca Cola 50ml", precio: 2950, stock: 61, imagen: "https://images.unsplash.com/photo-1560343090-f0409e92791a?q=80&w=400" },
    { nombre: "jugo Mineral 5L", precio: 1200, stock: 15, imagen: "https://images.unsplash.com/photo-1523362628745-0c100150b504?q=80&w=400"},
    { nombre: "cerveza con Gas 2L", precio: 800, stock: 0, imagen: "https://images.unsplash.com/photo-1523362628745-0c100150b504?q=80&w=400" },
    { nombre: "Soda", precio: 950, stock: 24, imagen: "https://images.unsplash.com/photo-1622483767028-3f66f32aef97?q=80&w=400" },
    { nombre: "Vino", precio: 1950, stock: 4, imagen: "https://images.unsplash.com/photo-1622483767028-3f66f32aef97?q=80&w=400" },
    { nombre: "Cepita", precio: 950, stock: 0, imagen: "https://images.unsplash.com/photo-1622483767028-3f66f32aef97?q=80&w=400" },
    { nombre: "Coca Cola 1,5l", precio: 2950, stock: 61, imagen: "https://images.unsplash.com/photo-1560343090-f0409e92791a?q=80&w=400"  },
    { nombre: "Manzana", precio: 1200, stock: 15, imagen: "https://images.unsplash.com/photo-1560343090-f0409e92791a?q=80&w=400" },
    { nombre: "Sandia", precio: 800, stock: 0, imagen: "https://images.unsplash.com/photo-1622483767028-3f66f32aef97?q=80&w=400" },
    { nombre: "Pera en Sifón", precio: 950, stock: 24, imagen: "https://images.unsplash.com/photo-1560343090-f0409e92791a?q=80&w=400" },
    { nombre: "Banana en lata", precio: 1950, stock: 4, imagen: "https://images.unsplash.com/photo-1622483767028-3f66f32aef97?q=80&w=400" },
    { nombre: "Aquarius en vino", precio: 950, stock: 0, imagen: "https://images.unsplash.com/photo-1560343090-f0409e92791a?q=80&w=400" },
    { nombre: "Coca Cola 500ml", precio: 2950, stock: 61, imagen: "https://images.unsplash.com/photo-1622483767028-3f66f32aef97?q=80&w=400" }
];

window.addEventListener('load', function (){

    const buscador = document.getElementById('buscador');
    const boton = document.getElementById('btn-buscar');
    const listaDiv = document.getElementById('lista-productos');

    // 1. CREAMOS UNA FUNCIÓN CON TU PROPIA LÓGICA
    function filtrarProductos() {
        listaDiv.innerHTML = "";
        const textoBuscado = buscador.value.toLowerCase();

        productos.forEach(function(producto) {
            const nombreProducto = producto.nombre.toLowerCase();

            if (nombreProducto.includes(textoBuscado) && producto.stock > 0) {
               listaDiv.innerHTML += `
                <div class="card-producto">
                        <img src="${producto.imagen}" alt="${producto.nombre}" class="prod-img">
                        <div class="prod-info">
                            <h3>${producto.nombre}</h3>
                            <p class="precio">$${producto.precio}</p>
                            <p class="stock">Stock: ${producto.stock} u.</p>
                        </div>
                    </div>
                `;
            }
        });

        if (listaDiv.innerHTML === "") {
            listaDiv.innerHTML = "<p>No se encontraron productos con stock disponible.</p>";
        }
    }

 
    buscador.addEventListener('input', filtrarProductos);
    boton.addEventListener('click', filtrarProductos);

    filtrarProductos(); 
});