<?php

// The flag is located at /flag.txt

$files = array_slice(scandir('files/'), 2);
$s = sizeof($files);

if ($s >= 10) {
    $i = 0;
    while ($s - $i >= 10) {
        unlink("files/" . $files[$i]);
        $i = $i + 1;
    }
}

$target_path = "/var/www/html/database/files/";
$allowed_extensions = array("jpg", "png", "pdf", "txt");

$filename = basename($_FILES['uploadedfile']['name']);
$file_extension = strtolower(pathinfo($filename, PATHINFO_EXTENSION));

if (in_array($file_extension, $allowed_extensions)) {
    $target_path = $target_path . $_FILES['uploadedfile']['name'];

    if (move_uploaded_file($_FILES['uploadedfile']['tmp_name'], $target_path)) {
        echo "<h1>The file was uploaded successfully</h1>";
    } else {
        echo "<h1>The file failed to upload</h1>";
    }
} else {
    echo "<h1>Invalid file type. Only .jpg, .png, .pdf, and .txt formats are allowed</h1>";
}
?>
