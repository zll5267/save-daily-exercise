var page = require('webpage').create();
var myPostChildPage;

page.onConsoleMessage = function(msg) {
    console.log('debug msg:' + msg);
};

page.onNavigationRequested = function() {
    console.log("page.onNavigationRequested");
};

page.onPageCreated = function(newPage) {
    console.log("A new child page created(mypost)");
    myPostChildPage = newPage;
    myPostChildPage.onConfirm = function() {
        console.log("page.onConfirm");
        return true;
    };
}

page.onConfirm = function() {
    console.log("page.onConfirm");
    return true;
};

page.onAlert = function() {
    console.log("page.onAlert");
};



page.open('http://www.58.com', function(status) {
    console.log("status:" + status);
    if (status == "success") {
        //console.log(page.content);
        //page.includeJs("http://j2.58cdn.com.cn/js/jquery-1.8.3.js", function() {
        page.evaluate(function() {
            //console.log("hello");
            console.log($("div#login a:first")[0]);
            //$("div#login a:first").click();
            var ev = document.createEvent("MouseEvents");
            ev.initEvent("click", true, true);
            document.querySelector("div#login").querySelector("a").dispatchEvent(ev);
        });
        //});
        setTimeout(function() {
            console.log("");
            console.log("redirect to login page");
            //page.render('test58.png');
            //page.evaluate(function() {
            //});
        }, 10000);

        setTimeout(function() {
            page.evaluate(function() {
                var ev = document.createEvent("MouseEvents");
                ev.initEvent("click", true, true);
                document.querySelector("#login_tab_orig").dispatchEvent(ev);
            });
            //page.render('test58.png');
        }, 11000);

        setTimeout(function() {
            page.evaluate(function() {
                document.querySelector("#username").value = "zlltest123";
                document.querySelector("#password").value = "zhang2016";
                var ev = document.createEvent("MouseEvents");
                ev.initEvent("click", true, true);
                document.querySelector("#btnSubmit").dispatchEvent(ev);
            });
            //page.render('test58.png');
        }, 12000);

        setTimeout(function() {
            console.log("login now..");
            //page.render('test58.png');
            page.evaluate(function() {
                var ev = document.createEvent("MouseEvents");
                ev.initEvent("click", true, true);
                document.querySelector("#tomypost").dispatchEvent(ev);
            });
        }, 17000);

        //setTimeout(function() {
        //    console.log("enter mypost ...");
        //    myPostChildPage.evaluate(function() {
        //        var ev = document.createEvent("MouseEvents");
        //        ev.initEvent("click", true, true);
        //        document.querySelector("a#del_25103019862192").dispatchEvent(ev);

        //        document.querySelector("span.swk-dbtn").dispatchEvent(ev);
        //    });
        //    myPostChildPage.render('test58.png');
        //}, 21000);

        setTimeout(function() {
            console.log("reopen post...");
            myPostChildPage.evaluate(function() {
                var ev = document.createEvent("MouseEvents");
                ev.initEvent("click", true, true);
                document.querySelector("a[href$=')']").dispatchEvent(ev);

                //document.querySelector("span.swk-dbtn").dispatchEvent(ev);
            });
            myPostChildPage.render('test58.png');
        }, 31000);
    }
});
