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

const fs = require('fs');

function mostrarMayusculas(rutaArchivo) {
  fs.readFile(rutaArchivo, 'utf-8', (err, data) => {
    if (err) {
      console.error('No se pudo leer el archivo:', err.message);
      return;
    }
    const nombres = data.split('\n').map(nombre => nombre.trim().toUpperCase());
    console.log('Nombres en mayúsculas:', nombres);
  });   // ← cierra el callback } y el readFile )
}


/*

Ejercicio 3: refactorización

Pasá esta función a async/await con try...catch:

const fs = require('fs/promises');

function sumarPrecios(ruta) {
  fs.readFile(ruta, 'utf-8')
    .then(texto => texto.split('\n'))
    .then(lineas => lineas.map(l => Number(l)))
    .then(precios => precios.reduce((acc, p) => acc + p, 0))
    .then(total => console.log('Total:', total))
    .catch(err => console.error('Error:', err.message));
}

*/

const fs = require('fs/promises');

async function sumarPrecios(ruta) {
  try {
    const texto = await fs.readFile(ruta, 'utf-8');
    const lineas = texto.split('\n');
    const precios = lineas.map(l => Number(l));
    const total = precios.reduce((acc, p) => acc + p, 0);
    console.log('Total:', total);
  } catch (err) {
    console.error('Error:', err.message);
  }
}



/*
Otro mas
function cargarUsuarios(url) {
  fetch(url)
    .then(res => res.json())
    .then(usuarios => usuarios.map(u => u.email))
    .then(emails => console.log(emails))
    .catch(err => console.error('Error:', err.message));
}

*/

async function cargarUsuarios(url) {
  try {
    const res = await fetch(url);
    const usuarios = await res.json();
    const emails = usuarios.map(u => u.email);
    console.log(emails);
  } catch (err) {
    console.error('Error:', err.message);
  }
}