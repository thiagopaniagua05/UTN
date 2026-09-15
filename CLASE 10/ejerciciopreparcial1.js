const pedidos = [
  { id: 101, cliente: 'TechCorp', items: 3, totalUSD: 1500, estado: 'COMPLETADO' },
  { id: 102, cliente: 'GlobalSvc', items: 1, totalUSD: 400, estado: 'CANCELADO' },
  { id: 103, cliente: 'InduData', items: 5, totalUSD: 2200, estado: 'COMPLETADO' },
  { id: 104, cliente: 'PymeLab', items: 2, totalUSD: 800, estado: 'PENDIENTE' },
  { id: 105, cliente: 'SistemasSA', items: 4, totalUSD: 3100, estado: 'COMPLETADO' }
];

const pedidosPipe = pedidos
    .filter(p => p.estado == "COMPLETADO")
    .map(p => p.totalUSD * 1200 * 1.10)
    .reduce((acum, montoTotal) => acum + montoTotal, 0);
    
    
console.log(pedidosPipe);

pedidosConCategoria = pedidos.map(p => {
    const categoriaCliente = p.items >= 4 ? "VIP" : "MENOR";
    return{
        ...p,
        categoriaCliente : categoriaCliente
    };
});
console.log(pedidosConCategoria);

const pedidosHtml = pedidosConCategoria.map(p =>
    `<ul class="lista-pedidos">
  <li>Pedido #${p.id} - ${p.cliente} (${p.categoriaCliente}) - Estado: ${p.estado}</li>
</ul>`).join("\n");
console.log(pedidosHtml);