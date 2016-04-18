<div class="container">
  <div class="author">
    <?php print t('Author') ?>: <span><?php print theme('username', array('account' => $data['#content'])); ?></span>
  </div>
  <div class="date">
    <?php print t('Date') ?>: <span><?php print format_date($data['#content']->created) ?></span>
  </div>
  <div class="tags">
    <?php print t('Tags') ?>: <span><?php print $data['#content']->tags ?></span>
  </div>
</div>