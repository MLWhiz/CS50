<div class="container">
  <table class="table table-striped">
    <thead>
      <tr>
        <th>Symbol</th>
        <th>Name</th>
        <th>Shares</th>
        <th>Price</th>
      </tr>
    </thead>
    <tbody>
    
<?php foreach ($positions as $position): ?>

    <tr>
        <td><?= $position["symbol"] ?></td>
        <td><?= $position["name"] ?></td>
        <td><?= $position["shares"] ?></td>
        <td><?= $position["price"] ?></td>
    </tr>

<?php endforeach ?>

    <tr>
        <td>CASH</td>
        <td></td>
        <td></td>
        <td><?= $cash ?></td>
    </tr>


    </tbody>
  </table>
</div>


