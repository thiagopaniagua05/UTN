<!DOCTYPE html>
<html lang="es">
<head>
    <meta charset="UTF-8">
    <title>Mi primer página en PHP</title>
</head>
<body>

    <h1>¡Hola desde HTML!</h1>

    <?php
        // Esto es código PHP puro ejecutándose en el servidor
        $nombre = "Thiago";
        echo "<p>¡Hola, " . $nombre . "! Este texto lo generó PHP de forma dinámica.</p>";
    ?>

</body>
</html>