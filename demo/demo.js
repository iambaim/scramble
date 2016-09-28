var domReady = function(callback) {
    document.readyState === "interactive" || document.readyState === "complete" ? callback() : document.addEventListener("DOMContentLoaded", callback);
};

domReady(function() {
  var ghpath = "https://raw.githubusercontent.com/iambaim/scramble/master/demo/";

  var limit = 20000;

  var methods = ["fmod", "mult", "none"];

  var methodsdetailed = ['#define _HASH_CONSTANT  11400714819323198485ULL</br>#define HASH(X) (X * _HASH_CONSTANT)', "#define HASH(X)         (uint64_t)floor(9223372036854775808ULL * MOD(X))</br>#define MOD(X) fmod((double)X * 0.61803398875, 1)", ""];

  var texts = [];
  texts["seq"] = "Sequential";
  texts["rand"] = "Random";

  var place = [];

  for (var k in texts) {

    var inputtype = texts[k];

    document.getElementById('content').innerHTML += "<h2>" + inputtype + " input</h2>";


    for (var l in methods) {

      var lp = parseInt(l) + 1;

      document.getElementById('content').innerHTML += "<h3>Hashing method: " + methods[l] + "</h3>";
      document.getElementById('content').innerHTML += "<div><code>" + methodsdetailed[l] + "</code></div><br/>";
      document.getElementById('content').innerHTML += '<div class="def" id="' + k + lp.toString() + '"></div><br/>';

    }
  }

  for (var k in texts) {

    var inputtype = texts[k];

    for (var l in methods) {

      var lp = parseInt(l) + 1;

      place[k + lp.toString()] = new Dygraph(
        document.getElementById(k + lp.toString()),
        ghpath + k + "." + methods[l] + "." + limit + ".out", // path to CSV file
        {
          title: inputtype + " with range: 0-" + limit,
          drawPoints: true,
          strokeWidth: 0,
          pointSize: 2,
        }
      );
    }
  }
})
