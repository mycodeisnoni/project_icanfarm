<template>
  <div class="chart-container" ref="container">
    <canvas ref="chart"></canvas>
  </div>
</template>

<script>
import Chart from 'chart.js/auto';

export default {
  name: 'DoughnutChart',
  props: {
    data: {
      type: Object,
      required: true,
    },
    options: {
      type: Object,
      default: () => ({
      }),
    },
  },
  mounted() {
    this.renderChart();
    // this.adjustHeight();
  },
  beforeUpdate() {
    if (this.chart) {
      this.chart.destroy();
      this.chart = null;
    }
  },
  beforeDestroy() {
    if (this.chart) {
      this.chart.destroy();
      this.chart = null;
    }
  },
  methods: {
    renderChart() {
      if (this.chart) {
        this.chart.destroy();
      }
      const ctx = this.$refs.chart.getContext('2d');
      this.chart = new Chart(ctx, {
        type: 'doughnut',
        data: this.data,
        options: this.options,
      });
    },
    // adjustHeight() {
    //   this.$nextTick(() => {
    //     const containerHeight = this.$refs.container.offsetHeight;
    //     this.$refs.chart.style.height = `${containerHeight}px`;
    //   });
    // },
  },
};
</script>

<style scoped>
/* .chart-container {
  position: relative;
  top: 0px;
  height: 10%;
  width: 100%;
  background-color: white;
}

.chart-container canvas {
  height: 100%;
} */
</style>