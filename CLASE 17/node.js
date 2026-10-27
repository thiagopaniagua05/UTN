const fs = require('fs/promises');

function contarAprobados(rutaArchivo) {
  fs.readFile(rutaArchivo, 'utf-8')
    .then(contenido => contenido.split('\n'))
    .then(lineas => lineas.map(linea => Number(linea.trim())))
    .then(notas => notas.filter(nota => nota >= 6))
    .then(aprobados => console.log(`Hay ${aprobados.length} aprobados`))
    .catch(err => console.error('Error al leer el archivo:', err.message));
}


const fs = require('fs/promises');

async function contarAprobados(rutaArchivo) {
  try {
    const contenido = await fs.readFile(rutaArchivo, 'utf-8');
    const notas = contenido.split('\n').map(linea => Number(linea.trim()));
    const aprobados = notas.filter(nota => nota >= 6);
    console.log(`Hay ${aprobados.length} aprobados`);
  } catch (err) {
    console.error('Error al leer el archivo:', err.message);
  }
}

/*

Ejercicio 1: fetch con async/await

Escribí la función obtenerProductosBaratos(url) usando async/await:

Hacé el fetch dentro de un try...catch.
Si la respuesta no es ok, lanzá un error con el status.
Convertí la respuesta con .json(). Te llega un array de objetos { nombre, precio }.
Imprimí y retorná un array con los nombres de los productos con precio menor a 500.

*/

async function obtenerProductosBaratos(url) {
  try {
    const respuesta = await fetch(url);

    if (!respuesta.ok) {
      throw new Error(`Error en la solicitud: ${respuesta.status}`);
    }

    const productos = await respuesta.json();
    const nombresBaratos = productos
      .filter(producto => producto.precio < 500)
      .map(producto => producto.nombre);

    console.log('Productos baratos:', nombresBaratos);
    return nombresBaratos;
  } catch (err) {
    console.error('Error al consultar la API:', err.message);
  }
}

/*

Ejercicio 2: callback error-first

Escribí la función mostrarMayusculas(rutaArchivo) usando fs.readFile con callback (el fs común, no fs/promises):

Si hay error, imprimí "No se pudo leer el archivo" y cortá la función.
Si sale bien, el archivo tiene un nombre por línea. Imprimí el array con todos los nombres en mayúsculas.

*/