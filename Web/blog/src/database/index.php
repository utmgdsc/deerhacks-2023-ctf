<html>

<head>
<title>Database</title>

<style>
body {
background: linear-gradient(135deg, #FFFFFF, #2843ff);
}
#files {
overflow-y: auto;
margin: auto;
border: 10px ridge grey;
border-radius: 5px;
height: 70%;
width: 35%;
}
#title {
text-align: center;
}
#desc {
text-align: center;
font-family: arial;
color: #4c4c4c;
}
#linkholder {
text-align: center;
margin: auto;
width: 100%;
}
</style>

</head>

<body>

<h1 id="title">Database</h1>
<p id="desc">This is a place where you can share<br>and download files.<br>Do not upload any malicious;<br>We have security measures in place.</p>

<div id="linkholder">
<a style="text-align: center;" href="upload.php">Upload A File</a>
</div>
<br>

<div id="files">
<?php include('documents.php'); ?>
</div>

</body>

</html>
