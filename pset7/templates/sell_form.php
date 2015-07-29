<form action="sell.php" method="post">
    <fieldset>
       <div class="form-group">
        SYMBOL: <select class="form-control" name="symbol">
                <option value=""> </option>
                   <?php foreach ($stocks as $position): ?> 
                <option value= <?= $position["symbol"]?>>
                    <?= $position["symbol"]?>
                </option>
                    <?php endforeach ?>
            </select>
       </div>     
    <div class="form-group">
            Number Of Shares: <input autofocus class="form-control" name="num_shares" placeholder="Number of Shares" type="text"/>
    </div>
     
    <div class="form-group">
        <button type="submit" class="btn btn-default">Sell Shares</button>
    </div>
    </fieldset>
</form>




