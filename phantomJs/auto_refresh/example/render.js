var page = require('webpage').create();
page.open('http://www.58.com', function(status) {
        console.log("status:" + status);
        if (status == "success") {
            page.render('render.png');
    }
    phantom.exit();
});
