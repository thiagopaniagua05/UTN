import React, { useState, useEffect } from 'react';
import {
  StyleSheet,
  Text,
  View,
  FlatList,
  ActivityIndicator,
  SafeAreaView,
  StatusBar,
  TouchableOpacity,
} from 'react-native';

// ---------------------------------------------------------------
// API SIMULADA (no la modifiques)
// Hace lo mismo que fetch(URL): devuelve una promesa que, al
// segundo, trae una respuesta con .ok, .status y .json().
// Así la cadena .then / .catch / .finally es igual a la del profe.
// ---------------------------------------------------------------
const EMPLEADOS = [
  { id: 1, nombre: 'Ana López', area: 'Sistemas', sueldo: 850000, activo: 1 },
  { id: 2, nombre: 'Juan Pérez', area: 'Ventas', sueldo: 620000, activo: 0 },
  { id: 3, nombre: 'Lucía Gómez', area: 'Sistemas', sueldo: 910000, activo: 1 },
  { id: 4, nombre: 'Martín Díaz', area: 'Ventas', sueldo: 540000, activo: 1 },
  { id: 5, nombre: 'Sofía Ruiz', area: 'Sistemas', sueldo: 780000, activo: 0 },
  { id: 6, nombre: 'Diego Torres', area: 'Ventas', sueldo: 820000, activo: 1 },
];

const fetchSimulado = () =>
  new Promise((resolve) => {
    setTimeout(() => {
      resolve({
        ok: true,
        status: 200,
        json: () => Promise.resolve({ status: 'success', data: EMPLEADOS }),
      });
    }, 1000);
  });

// ---------------------------------------------------------------
// APP
// ---------------------------------------------------------------
export default function App() {
  const [empleados, setEmpleados] = useState([]);
  const [cargando, setCargando] = useState(true);
  const [error, setError] = useState(null);
  const [filtroArea, setFiltroArea] = useState('Todos');

  const consultarEmpleados = () => {
    setCargando(true);
    setError(null);

    fetchSimulado()
      .then(response => {
        if (!response.ok) {
          throw new Error(`Error HTTP: ${response.status}`);
        }
        return response.json();
      })
      .then(json => {
        if (json.status === 'success') {
          setEmpleados(json.data);
        } else {
          throw new Error('Formato de respuesta no reconocido');
        }
      })
      .catch(err => {
        console.error(err);
        setError('No se pudo obtener la lista de empleados');
      })
      .finally(() => {
        setCargando(false);
      });
  };

  useEffect(() => {
    consultarEmpleados();
  }, []);

  const renderEmpleado = ({ item }) => {
    return (
      <View style={styles.card}>
        <View style={styles.cardHeader}>
          <Text style={styles.idTexto}>ID #{item.id}</Text>
          <Text style={styles.areaTexto}>{item.area}</Text>
        </View>
        <Text style={styles.nombreTexto}>{item.nombre}</Text>
        <Text style={[styles.sueldo, item.sueldo > 800000 && styles.sueldoAlto]}>
          ${item.sueldo.toLocaleString('es-AR')}
        </Text>
        <Text style={[styles.estado, item.activo === 1 ? styles.activo : styles.inactivo]}>
          {item.activo === 1 ? 'ACTIVO' : 'INACTIVO'}
        </Text>
      </View>
    );
  };

const filtrarEmpleados = empleados.filter(a => filtroArea === 'Todos' || a.area === filtroArea);

  return (
    <SafeAreaView style={styles.container}>
      <StatusBar barStyle="dark-content" />

      <View style={styles.encabezado}>
        <Text style={styles.titulo}>Empleados</Text>
        <Text>Activos: {empleados.filter(x => x.activo === 1).length} de {empleados.length} empleados</Text>
      </View>


<View style={styles.filaBotones}>
  <TouchableOpacity style={styles.botonFiltro} onPress={() => setFiltroArea('Todos')}>
    <Text style={styles.textoBoton}>Todos</Text>
  </TouchableOpacity>
  <TouchableOpacity style={styles.botonFiltro} onPress={() => setFiltroArea('Sistemas')}>
    <Text style={styles.textoBoton}>Sistemas</Text>
  </TouchableOpacity>
  <TouchableOpacity style={styles.botonFiltro} onPress={() => setFiltroArea('Ventas')}>
    <Text style={styles.textoBoton}>Ventas</Text>
  </TouchableOpacity>
</View>

      {cargando ? (
        <View style={styles.centro}>
          <ActivityIndicator size="large" color="#2b6cb0" />
          <Text style={styles.textoEstado}>Cargando empleados...</Text>
        </View>
      ) : error ? (
        <View style={styles.centro}>
          <Text style={styles.textoError}>{error}</Text>
          <TouchableOpacity style={styles.boton} onPress={consultarEmpleados}>
            <Text style={styles.textoBoton}>Reintentar</Text>
          </TouchableOpacity>
        </View>
      ) : (
        <FlatList
          data={filtrarEmpleados}
          keyExtractor={(item) => item.id.toString()}
          renderItem={renderEmpleado}
          contentContainerStyle={styles.lista}
          onRefresh={consultarEmpleados}
          refreshing={cargando}
          ListEmptyComponent={<Text style={styles.textoEstado}>No hay empleados.</Text>}
        />
      )}
    </SafeAreaView>
  );
}

const styles = StyleSheet.create({
  container: {
    flex: 1,
    backgroundColor: '#f0f4f8',
    paddingTop: 35,
  },
  encabezado: {
    paddingHorizontal: 20,
    paddingBottom: 15,
    borderBottomWidth: 1,
    borderBottomColor: '#d9e2ec',
  },
  titulo: {
    fontSize: 22,
    fontWeight: 'bold',
    color: '#102a43',
  },
  sueldo:{
    fontSize: 14,
    color: '#334e68',
    marginTop: 4,
  },
  sueldoAlto: {
    color: '#2f855a',
    fontWeight: 'bold',
  }
  ,
  filaBotones: {
  flexDirection: 'row',
  justifyContent: 'space-around',
  paddingVertical: 12,
},
botonFiltro: {
  backgroundColor: '#3182ce',
  paddingVertical: 8,
  paddingHorizontal: 16,
  borderRadius: 8,
},
  lista: {
    padding: 16,
  },
  card: {
    backgroundColor: '#ffffff',
    borderRadius: 12,
    padding: 16,
    marginBottom: 12,
    elevation: 3,
    shadowColor: '#000',
    shadowOffset: { width: 0, height: 2 },
    shadowOpacity: 0.08,
    shadowRadius: 4,
  },
  cardHeader: {
    flexDirection: 'row',
    justifyContent: 'space-between',
    marginBottom: 8,
  },
  idTexto: {
    fontSize: 13,
    fontWeight: 'bold',
    color: '#829ab1',
  },
  areaTexto: {
    fontSize: 13,
    fontWeight: 'bold',
    color: '#2b6cb0',
    textTransform: 'uppercase',
  },
  nombreTexto: {
    fontSize: 16,
    fontWeight: '600',
    color: '#243b53',
  },
 estado: {
  alignSelf: 'flex-start',
  marginTop: 8,
  paddingVertical: 4,
  paddingHorizontal: 10,
  borderRadius: 6,
  fontSize: 12,
  fontWeight: 'bold',
},
activo: {
  backgroundColor: '#c6f6d5',
  color: '#22543d',
},
inactivo: {
  backgroundColor: '#e2e8f0',
  color: '#4a5568',
},
  centro: {
    flex: 1,
    justifyContent: 'center',
    alignItems: 'center',
    padding: 24,
  },
  textoEstado: {
    marginTop: 12,
    color: '#486581',
    fontSize: 15,
    textAlign: 'center',
  },
  textoError: {
    color: '#c53030',
    fontSize: 15,
    textAlign: 'center',
    marginBottom: 16,
  },
  boton: {
    backgroundColor: '#3182ce',
    paddingVertical: 10,
    paddingHorizontal: 20,
    borderRadius: 8,
  },
  textoBoton: {
    color: '#ffffff',
    fontWeight: 'bold',
  },
});
