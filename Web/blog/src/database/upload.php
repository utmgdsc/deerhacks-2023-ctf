<html>

<head>
<title>File Share</title>

<style>
body {
background: linear-gradient(135deg, #FFFFFF, #2843ff);
}
#title {
text-align: center;
}
#desc {
text-align: center;
font-family: arial;
color: #4c4c4c;
}
#upload {
text-align: center;
height: 20%;
width: 30%;
border: 10px ridge grey;
margin: auto;
}
</style>

</head>

<body>

<h1 id="title">File Share</h1>
<p id="desc">This is a place where you can view<br>and download files others have uploaded.<br>Do not upload any malicious files! Protections are in place.</p>

<div id="upload">
<form enctype="multipart/form-data" action="uploader.php" method="POST">

<input type="hidden" name="MAX_FILE_SIZE" value="100000">

<p style="text-align: center;">Choose a file to upload:</p>

<input name="uploadedfile" type="file"/>
<br>
<br>
<input type="submit" value="Upload File" />
</form>
</div>

</body>

</html>
