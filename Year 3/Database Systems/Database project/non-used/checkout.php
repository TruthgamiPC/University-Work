<?php
include 'header.php';
?>
<!-- bootsrtap row -->
<div class="container-fluid">
  <div class="row">
    <div class="col-sm-12">
      <h3>Placeholder product name</h3>
      <p>Product name</p>
      <p>Product price</p>
      <p>Would you like to buy this product?</p>
      <div class="row">
      <div class="col-6 col-sm-6">
      <button class="btn btn-info btn-md" id="YesButton">Yes</button>
      </div>
      <div class="col-6 col-sm-6">
      <button class="btn btn-info btn-md" id="NoButton">No</button>
      </div>
    </div>
  </div>
</div>

<script type="text/javascript">
    document.getElementById("YesButton").onclick = function () {
      alert('Purchase Successful');
    };
</script>

<script type="text/javascript">
    document.getElementById("NoButton").onclick = function () {
      alert('Purchase Cancelled');
    };
</script>

<?php
include 'footer.php';
?>
