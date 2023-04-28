<?php

// The flag is located at /flag.txt

$files = array_slice(scandir('files/'), 2);

$s = sizeof($files);
$i = 0;

while($i < $s) {
	if ($files[$i] != "") {
		echo "<div style='height: 5%; width: 80%; border-bottom: 2px solid black;'><span style='margin: 5px; float: left;'> <a href='download.php?filename=" . $files[$i] . "'>" . $files[$i] . "</a> </span> <span style='margin: 5px; float: right;'>	<a href='download.php?filename=" . $files[$i] . "'>Download</a> </span></div><br>";
	}
	$i = $i + 1;
}
?>
