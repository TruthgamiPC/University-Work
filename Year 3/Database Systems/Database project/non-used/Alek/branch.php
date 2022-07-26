<?php
include 'header.php';
include 'branchHead.php';
?>


<script> var coordinates = [-2.99,56.84]; </script>

<!-- bootsrtap row -->

<div class="container-fluid">
<div class="row">
  <div class="col-sm-12">
    <h3>Branch Details</h3>
    <div class="row">
        <div class="col-3 col-sm-6">
            <p>Branch name</p>
            <p>Branch Number</p>
            <p>Branch Open Time</p>
            <p>Branch Close Time</p>
            <p>Branch Manager</p>
            <!-- branch address dropdown -->
            <div class="dropdown">
              <button class="dropbtn">Store Location</button>
              <div class="dropdown-content">
                <p></p>
                <button class="btn btn-info btn-md" id="Dundee">Dundee</button>
                <p></p>
                <button class="btn btn-info btn-md" id="Perth">Perth</button>
                <p></p>
                <button class="btn btn-info btn-md" id="Kirkcaldy">Kirkcaldy</button>
                <p></p>
                <button class="btn btn-info btn-md" id="Dunfermline">Dunfermline</button>
                <p></p>
                <button class="btn btn-info btn-md" id="Edinburgh">Edinburgh</button>
              </div>
            </div>
            <p>Branch Address Line 1</p>
            <p>Branch Address Line 2</p>
            <p>Branch Address Line 1</p>
            <p>Branch Address Post Code</p>
            <p>Branch Address City</p>
            <p>Branch Address Country</p>
        </div>
        <div class="col-9 col-sm-6">
        <!--taken from https://openlayers.org/en/latest/doc/quickstart.html -->    
        <h3>Branch Location</h3>
        <!--The div element for the map -->
        <div id="map" class="map"></div>
        </div>
    </div>
  </div>
</div>
</div>

<!--taken from https://openlayers.org/en/latest/doc/quickstart.html -->
<script type="text/javascript">

      
    document.getElementById("Dundee").onclick = function () {
      coordinates = [-2.99, 56.48]
      var map = new ol.Map({
        target: 'map',
        layers: [
          new ol.layer.Tile({
            source: new ol.source.OSM()
          })
        ],
        view: new ol.View({
          center: ol.proj.fromLonLat(coordinates),
          zoom: 7
        })
      });
    };

    document.getElementById("Perth").onclick = function () {
      coordinates = [-3.43, 56.42]
      var map = new ol.Map({
        target: 'map',
        layers: [
          new ol.layer.Tile({
            source: new ol.source.OSM()
          })
        ],
        view: new ol.View({
          center: ol.proj.fromLonLat(coordinates),
          zoom: 7
        })
      });
    };

    document.getElementById("Kirkcaldy").onclick = function () {
      coordinates = [-3.19,56.10]
      var map = new ol.Map({
        target: 'map',
        layers: [
          new ol.layer.Tile({
            source: new ol.source.OSM()
          })
        ],
        view: new ol.View({
          center: ol.proj.fromLonLat(coordinates),
          zoom: 7
        })
      });
    };
    
    document.getElementById("Dunfermline").onclick = function () {
      coordinates = [-3.37,56.10]
      var map = new ol.Map({
        target: 'map',
        layers: [
          new ol.layer.Tile({
            source: new ol.source.OSM()
          })
        ],
        view: new ol.View({
          center: ol.proj.fromLonLat(coordinates),
          zoom: 7
        })
      });
    };

    
    document.getElementById("Edinburgh").onclick = function () {
      coordinates = [-3.22,55.98]
      var map = new ol.Map({
        target: 'map',
        layers: [
          new ol.layer.Tile({
            source: new ol.source.OSM()
          })
        ],
        view: new ol.View({
          center: ol.proj.fromLonLat(coordinates),
          zoom: 7
        })
      });
    };
    </script>

<?php
include 'footer.php';
?>
