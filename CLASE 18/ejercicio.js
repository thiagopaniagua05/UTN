const pedidos = [
  { id: 1, cliente: 'Ana', total: 12000, estado: 'pagado' },
  { id: 2, cliente: 'Luis', total: 8500, estado: 'pendiente' },
  { id: 3, cliente: 'Ana', total: 4300, estado: 'pagado' },
  { id: 4, cliente: 'Sofía', total: 15000, estado: 'cancelado' },
  { id: 5, cliente: 'Luis', total: 9700, estado: 'pagado' },
];

function pedidosPagados() {
  return pedidos.filter(pedido => pedido.estado === 'pagado');
}

function clientesUnicos() {
  const nombres = pedidos.map(pedido => pedido.cliente);
  return [...new Set(nombres)];
}

function totalPagado() {
  return pedidosPagados().reduce((acumulado, pedido) => acumulado + pedido.total, 0);
}


function pedidoMasCaro() {
  return pedidos.reduce((masCaro, pedido) => {
    if (pedido.total > masCaro.total) {
      return pedido;
    }
    return masCaro;
  });
}

function pedidoMasBajo() {
  return pedidos.reduce((masBajo, pedido) => {
    if (pedido.total < masBajo.total) {
      return pedido;
    }
    return masBajo;
  });
}

function pedidosPendientes() {
  return pedidos.filter(pedido => pedido.estado === 'pendiente');
}
function totalPendiente() {
  return pedidosPendientes().reduce((acumulado, pedido) => acumulado + pedido.total, 0);
}

