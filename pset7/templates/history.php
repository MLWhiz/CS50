<div class="container">
  <table class="table table-striped">
    <thead>
      <tr>
        <th>Symbol</th>
        <th>Type</th>
        <th>Name</th>
        <th>Shares</th>
        <th>Price</th>
        <th>Datetime</th>
      </tr>
    </thead>
    <tbody>
    
<?php foreach ($transactions as $position): ?>

    <?php if($position["type"]=='BUY'): ?>
    <tr class="success">
        <td><?= $position["symbol"] ?></td>
        <td><?= $position["type"] ?></td>
        <td><?= $position["name"] ?></td>
        <td><?= $position["shares"] ?></td>
        <td><?= $position["price"] ?></td>
        <td><?= $position["dt"] ?></td>
    </tr>
    <?php else: ?>
    <tr class="warning">
        <td><?= $position["symbol"] ?></td>
        <td><?= $position["type"] ?></td>
        <td><?= $position["name"] ?></td>
        <td><?= $position["shares"] ?></td>
        <td><?= $position["price"] ?></td>
        <td><?= $position["dt"] ?></td>
    </tr>
    <?php endif ?>    

<?php endforeach ?>


    </tbody>
  </table>
</div>


<div>
    <a href="logout.php">Log Out</a>
</div>
