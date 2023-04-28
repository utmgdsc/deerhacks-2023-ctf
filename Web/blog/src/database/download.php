<?php

// The flag is located at /flag.txt

if (isset($_REQUEST['filename'])) {
    $filename = $_REQUEST['filename'];
    $validated_filename = isset($_GET['filename']) ? $_GET['filename'] : "";

    if (empty($filename)) {
        echo "Please provide a file name.";
        exit;
    }

    if (empty($validated_filename) || !preg_match('/^[\w\-\.]+$/', $validated_filename)) {
        echo "Invalid file name. Only alphanumeric characters, hyphens, underscores, and periods are allowed.";
        exit;
    }

    $directory = "files/";
    $file_path = $directory . $filename;

    if (file_exists($file_path)) {
        header('Content-Description: File Transfer');
        header('Content-Type: application/octet-stream');
        header('Content-Disposition: attachment; filename="' . basename($file_path) . '"');
        header('Expires: 0');
        header('Cache-Control: must-revalidate');
        header('Pragma: public');
        header('Content-Length: ' . filesize($file_path));
        readfile($file_path);
        exit;
    } else {
        echo "File not found.";
    }
} else {
    echo "No file name provided.";
}
?>