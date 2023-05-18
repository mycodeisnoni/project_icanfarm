<template>
  <div class="chart-container" ref="container">
    <canvas ref="lineChart" height="70"></canvas>
  </div>
</template>

<script>
import Chart from 'chart.js/auto';

export default {
  name: 'LineChart',
  props: {
    chart: null,
    chartData: {
      type: Object,
      required: true,
    },
    chartOptions: {
      type: Object,
      default: () => ({
        plugins:{
          legend:{
            display: false
          }
        },
      }),
    },
  },
  mounted() {
    this.renderChart();
  },
  beforeUpdate() {
    // if (this.chart) {
    //   this.chart.destroy();
    //   this.chart = null;
    // }
    this.renderChart();
  },
  beforeDestroy() {
    if (this.lineChart) {
      this.lineChart.destroy();
      this.chart = null;
    }
  },
  methods: {
    renderChart() {
      if (this.chart) {
        this.chart.destroy();
      }
      const canvas = this.$refs.lineChart;
      this.lineChart = new Chart(canvas, {
        type: 'line',
        data: this.chartData,
        options: this.chartOptions,
      });
    },
  },

};
</script>