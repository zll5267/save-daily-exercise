var page = require('webpage').create();
page.onConsoleMessage = function(msg) {
    console.log('Page title is ' + msg);
};

var url = "http://www.58.com";

page.open(url, function(status) {
    page.evaluate(function() {
        console.log(document.title);
    });
    phantom.exit();
});
