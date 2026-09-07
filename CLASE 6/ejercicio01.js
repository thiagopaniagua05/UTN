const ventas = [
  { id: 'V101', producto: 'Teclado Mecánico', monto: 45000, estado: 'completada' },
  { id: 'V102', producto: 'Mouse Gamer', monto: 18000, estado: 'cancelada' },
  { id: 'V103', producto: 'Monitor 24"', monto: 160000, estado: 'completada' },
  { id: 'V104', producto: 'Placa de Video', monto: 520000, estado: 'completada' },
  { id: 'V105', producto: 'Auriculares', monto: 35000, estado: 'cancelada' }
];
// 1
const ventasExitosas = ventas.filter(p => p.estado === "completada");
console.log(ventasExitosas);

//2
console.log("PUNTO 2");
const ventasComisiones = ventasExitosas.map(v =>{
    const comisionMercado = v.monto * 0.13;
    return {
        ...v,
        comisionMercado: comisionMercado
    };
});
console.log(ventasComisiones);



//ejercicio 2

const componentes = [
  { sku: 501, nombre: 'Placa Madre B550', precioUSD: 120, destacado: true },
  { sku: 502, nombre: 'Procesador Ryzen 5', precioUSD: 180, destacado: false },
  { sku: 503, nombre: 'Memoria RAM 16GB', precioUSD: 45, destacado: true },
  { sku: 504, nombre: 'Fuente 650W Gold', precioUSD: 90, destacado: false }
];

const componentesPesificados = componentes.map(c =>{
    const precioARS = c.precioUSD * 1200;
    const etiqueta = c.destacado == true ? "DESTACADO" : "NORMAL";
    
    return{
        ...c, precioARS: precioARS, etiqueta: etiqueta
    };
});
//otra manera
const componentesPesificados2 = componentes.map(c => ({
    ...c,
    precioARS: c.precioUSD *1200,
    etiqueta: c.destacado == true ? "DESTACADO" : "NORMAL"
}));
console.table(componentesPesificados);
console.table(componentesPesificados2);

const componentesHTML = componentesPesificados.map(componente => `<div class="card">
  <h3>${componente.nombre}</h3>
  <p>${componente.precioARS}</p>
  <span>${componente.etiqueta}</span>
</div>`)
.join('\n');
console.log(componentesHTML);

