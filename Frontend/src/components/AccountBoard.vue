.<template>
  <div class="container">
    <div class="item1">
      <div class="ICON"></div>
    </div>
    <div class="item2">

    </div>
  </div>
</template>

<script>
export default {

}
</script>

<style scoped>
.container{
  display: flex;
}
.item1{
  background-color: rgb(169, 201, 202);
  position: absolute;
  width: 20%;
  height: 100%;
  top: 0;
  left: 0;
}
.ICON{
  background-image: url("../assets/ICON_ICANFARM.png");
  background-size: cover;
  position: relative;
  width: 100px;
  height: 110px;
  top: 1%;
  Left: 1%;
}

</style>