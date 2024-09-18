// MainWindow.xaml.cs
using System;
using System.Windows;

namespace AdivinanzaApp
{
    public partial class MainWindow : Window
    {
        private int numeroAleatorio; // Número que debe ser adivinado
        private int intentosFallidos; // Contador de intentos fallidos
        private Random random;

        public MainWindow()
        {
            InitializeComponent();
            random = new Random();
            ReiniciarJuego(); // Generar el primer número
        }

        // Método para manejar el botón de verificación
        private void VerificarIntento_Click(object sender, RoutedEventArgs e)
        {
            int intentoUsuario;

            // Verificamos que la entrada del usuario sea un número válido
            if (int.TryParse(InputTextBox.Text, out intentoUsuario))
            {
                // Comparar con el número aleatorio generado
                string resultadoIntento;

                if (intentoUsuario < numeroAleatorio)
                {
                    resultadoIntento = $"Intento {intentoUsuario}: El número es mayor.";
                    intentosFallidos++; // Aumentar intentos fallidos
                    InputTextBox.Text = "";
                }
                else if (intentoUsuario > numeroAleatorio)
                {
                    resultadoIntento = $"Intento {intentoUsuario}: El número es menor.";
                    intentosFallidos++; // Aumentar intentos fallidos
                    InputTextBox.Text = "";
                }
                else
                {
                    resultadoIntento = $"Intento {intentoUsuario}: ¡Correcto!";
                    ReiniciarButton.IsEnabled = true; // Habilitar el botón de reinicio
                    VerificarButton.IsEnabled = false; // Deshabilitar el botón de verificar
                }

                // Actualizamos el TextBlock de intentos fallidos
                IntentosTextBlock.Text = $"Intentos fallidos: {intentosFallidos}";

                // Añadimos el intento al historial
                HistorialListBox.Items.Add(resultadoIntento);
            }
            else
            {
                PistaTextBlock.Text = "Por favor, ingresa un número válido.";
            }
        }

        // Método para manejar el botón de reinicio
        private void ReiniciarJuego_Click(object sender, RoutedEventArgs e)
        {
            ReiniciarJuego();
        }

        // Método que reinicia el juego generando un nuevo número aleatorio
        private void ReiniciarJuego()
        {
            numeroAleatorio = random.Next(1, 101); // Generar número entre 1 y 100
            intentosFallidos = 0; // Reiniciar contador de intentos fallidos
            PistaTextBlock.Text = "Introduce un número para comenzar.";
            InputTextBox.Clear();
            IntentosTextBlock.Text = $"Intentos fallidos: {intentosFallidos}"; // Mostrar intentos fallidos reiniciados
            HistorialListBox.Items.Clear(); // Limpiar historial de intentos
            ReiniciarButton.IsEnabled = false; // Deshabilitar el botón de reinicio
            VerificarButton.IsEnabled = true; // Habilitar el botón de verificar
        }
    }
}
