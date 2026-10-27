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