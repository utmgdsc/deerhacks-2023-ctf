const express = require('express');    //Express Web Server
const busboy = require('connect-busboy'); //middleware for form/file upload
const path = require('path');     //used for file path
const fs = require('fs'); // interact with the file system
const {exec} = require("child_process"); // execute shell commands
const app = express(); // create express app, handles http requests
app.use(busboy({limits: {fileSize: 1e+8, files: 1}})); // middleware to accept form/file upload
app.use(express.static(path.join(__dirname, 'public'))); // let users freely access the /public folder

// Main upload endpointz
app.post('/upload', function (req, res, next) {
    if (!req.busboy) {
        return res.send(400)
    }
    // process the file data
    req.pipe(req.busboy);
    // TODO what if someone uploads different files with the same name at the same time?
    // handle file upload (trigger callback when done processing)
    req.busboy.on('file', function (fieldname, file, filedata) {
        console.log("Uploading: " + JSON.stringify(filedata));
        // write the file to the /upload folder
        let fstream = fs.createWriteStream(__dirname + '/upload/' + filedata.filename);
        file.pipe(fstream);

        // when the file is done uploading, modify it
        fstream.on('close', function () {
            console.log("Upload Finished of " + filedata.filename);
            if (file.truncated) {
                res.statusCode = 400
                res.send("File size too big")
                return
            }
            const command = `./encrypt "${__dirname + '/upload/' + filedata.filename}"`
            // excute the shell script to modify the audio (using ffmpeg)
            exec(command, (error, stdout, stderr) => {
                // TODO why is regular output considered stderr?
                if (stderr) {
                    console.log(`stderr: ${stderr}`);
                }
                console.log(`stdout: ${stdout}`);

                // send the modified file to the user
                res.send({output: ['$ ' + command, stdout, stderr].join('\n')})
            });
        });
    });
});

// start the server at port 3030
const server = app.listen(3030, function () {
    console.log('Listening on port %d', server.address().port);
});
