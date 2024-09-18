using System;
using System.Globalization;
using System.Windows;

namespace TipCalculatorApp
{
    public partial class MainWindow : Window
    {
        public MainWindow()
        {
            InitializeComponent();
        }

        // Método para manejar el cálculo de la propina
        private void CalcularPropina_Click(object sender, RoutedEventArgs e)
        {
            // Validación del monto ingresado
            if (decimal.TryParse(MontoTextBox.Text, NumberStyles.Currency, CultureInfo.InvariantCulture, out decimal montoTotal))
            {
                // Obtener el porcentaje de propina del Slider
                decimal porcentajePropina = (decimal)PropinaSlider.Value;

                // Calcular la propina
                decimal propina = montoTotal * (porcentajePropina / 100);

                // Calcular el total con la propina
                decimal totalConPropina = montoTotal + propina;

                // Mostrar los resultados en el TextBlock
                ResultadoTextBlock.Text = $"Propina: {propina:C2}\nTotal con propina: {totalConPropina:C2}";
            }
            else
            {
                // Si el monto no es válido, mostrar mensaje de error
                ResultadoTextBlock.Text = "Por favor, ingresa un monto válido.";
            }
        }
    }
}
