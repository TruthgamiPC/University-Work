<?php
include 'header.php';
?>
<!-- bootsrtap row -->
<div class="container-fluid">
<div class="row">
  <div class="col-sm-12">
    <h3>Product name</h3>
    <div class="row">
      <div class="col-3 col-sm-6">
            <p>Product name</p>
            <p>Product type</p>
            <p>Product brand</p>
            <p>Product supplier</p>
            <p>Product model</p>
            <p>Product price</p>
            <p>Product description</p>
            <button class="btn btn-info btn-md" id="PurchaseButton">Purchase Item</button>
      </div>
      <div class="col-9 col-sm-6">
        <img src="https://www.pngkey.com/png/detail/75-759952_big-red-x-png-red-x-3d-png.png" alt="Placeholder product image" style="width:100%">
      </div>
    </div>
  </div>
</div>
</div>

<script type="text/javascript">
    document.getElementById("PurchaseButton").onclick = function () {
        location.href = "checkout.php";
    };
</script>

<?php
include 'footer.php';
?>
