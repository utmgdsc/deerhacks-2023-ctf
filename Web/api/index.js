const express = require('express')
const app = express()
const port = process.env.PORT || 3030

app.use(express.static('public'))
app.use((req,res)=>res.redirect("https://ctf.gdscutm.com/"))


app.listen(port, () => {
    console.log(`Example app listening on port ${port}`)
})
