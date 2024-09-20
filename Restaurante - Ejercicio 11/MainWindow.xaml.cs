using System;
using System.Collections.Generic;
using System.Linq;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Media;
using System.Windows.Media.Imaging;

namespace FoodExplorer
{
    public partial class MainWindow : Window
    {
        private Dictionary<string, List<int>> productRatings = new Dictionary<string, List<int>>();
        private Dictionary<string, List<string>> selectedOptions = new Dictionary<string, List<string>>(); // Almacena opciones seleccionadas
        private string selectedProduct;

        // URLs de las imágenes de las estrellas desde la web
        private string fullStarUrl = "https://w7.pngwing.com/pngs/134/138/png-transparent-star-golden-stars-angle-3d-computer-graphics-symmetry-thumbnail.png"; // Reemplazar con una URL válida
        private string emptyStarUrl = "https://e7.pngegg.com/pngimages/508/846/png-clipart-star-star-angle-triangle.png"; // Reemplazar con una URL válida
        public MainWindow()
        {
            InitializeComponent();
            // Configurar la ventana en pantalla completa al iniciar
            this.WindowState = WindowState.Maximized;
        }

        // Evento para seleccionar categoría
        private void Category_Click(object sender, RoutedEventArgs e)
        {
            var button = sender as Button;
            string category = button.Content.ToString();

            // Actualiza la lista de productos basados en la categoría seleccionada
            ProductList.Items.Clear();
            selectedProduct = null;
            ProductName.Text = "";
            ProductOptions.Items.Clear();
            ResetStars(); // Resetea las estrellas cuando se cambia la categoría.

            switch (category)
            {
                case "🍔 Burger":
                    ProductList.Items.Add("Cheeseburger");
                    ProductList.Items.Add("Bacon Burger");
                    break;
                case "🍕 Pizza":
                    ProductList.Items.Add("Sicilian Pizza");
                    ProductList.Items.Add("Pepperoni Pizza");
                    ProductList.Items.Add("Hawaiian Pizza");
                    break;
                case "🍰 Dessert":
                    ProductList.Items.Add("Chocolate Cake");
                    ProductList.Items.Add("Ice Cream Sundae");
                    break;
                case "🍟 French":
                    ProductList.Items.Add("French Fries");
                    ProductList.Items.Add("Croissant");
                    break;
                case "🍹 Drinks":
                    ProductList.Items.Add("Lemonade");
                    ProductList.Items.Add("Iced Coffee");
                    break;
                case "🥡 Chinese":
                    ProductList.Items.Add("Kung Pao Chicken");
                    ProductList.Items.Add("Sweet and Sour Pork");
                    break;
            }
        }

        // Evento para seleccionar producto
        private void ProductList_SelectionChanged(object sender, System.Windows.Controls.SelectionChangedEventArgs e)
        {
            if (ProductList.SelectedItem != null)
            {
                selectedProduct = ProductList.SelectedItem.ToString();
                ProductName.Text = selectedProduct;

                // Limpiar las opciones del producto para evitar duplicados
                ProductOptions.Items.Clear();

                // Agregar nuevas opciones según el producto seleccionado
                List<string> options = new List<string>();
                /*if (selectedProduct == "Cheeseburger")
                {
                    ProductOptions.Items.Add(CreateOptionItem("Extra Cheese"));
                    ProductOptions.Items.Add(CreateOptionItem("Bacon"));
                    ProductOptions.Items.Add(CreateOptionItem("Double Patty"));
                    //options.Add("Extra Cheese"); OTRA FORMA DE HACERLO
                    //options.Add("Bacon");
                }
                else if (selectedProduct == "Bacon Burger")
                {
                    ProductOptions.Items.Add(CreateOptionItem("BBQ Sauce"));
                    ProductOptions.Items.Add(CreateOptionItem("Onion Rings"));
                    //options.Add("BBQ Sauce");
                    //options.Add("Onion Rings");
                }
                else if (selectedProduct == "Sicilian Pizza")
                {
                    ProductOptions.Items.Add(CreateOptionItem("Extra Olives"));
                    ProductOptions.Items.Add(CreateOptionItem("Double Cheese"));
                    //options.Add("Extra Olives");
                    //options.Add("Double Cheese");
                }*/

                // Asignar imágenes personalizadas según el producto seleccionado
                string imagePath = "Images/default.png"; // Ruta por defecto
                switch (selectedProduct)
                {
                    // Burger Category
                    case "Cheeseburger":
                        options.Add("Extra Cheese");
                        options.Add("Bacon");
                        options.Add("Double Patty");
                        imagePath = "Images/cheeseburger.png";
                        break;
                    case "Bacon Burger":
                        options.Add("BBQ Sauce");
                        options.Add("Onion Rings");
                        options.Add("Extra Bacon");
                        imagePath = "Images/cheeseburger.png";
                        break;

                    // Pizza Category
                    case "Sicilian Pizza":
                        options.Add("Extra Olives");
                        options.Add("Double Cheese");
                        options.Add("Thin Crust");
                        imagePath = "Images/cheeseburger.png";
                        break;
                    case "Pepperoni Pizza":
                        options.Add("Extra Pepperoni");
                        options.Add("Stuffed Crust");
                        options.Add("Gluten Free");
                        imagePath = "Images/cheeseburger.png";
                        break;
                    case "Hawaiian Pizza":
                        options.Add("Extra Pineapple");
                        options.Add("No Ham");
                        options.Add("Extra Cheese");
                        imagePath = "Images/cheeseburger.png";
                        break;

                    // Dessert Category
                    case "Chocolate Cake":
                        options.Add("Extra Chocolate");
                        options.Add("Whipped Cream");
                        options.Add("Nuts");
                        imagePath = "Images/cheeseburger.png";
                        break;
                    case "Ice Cream Sundae":
                        options.Add("Chocolate Syrup");
                        options.Add("Sprinkles");
                        options.Add("Extra Scoop");
                        imagePath = "https://image.similarpng.com/very-thumbnail/2022/01/Ice-cream-sundae-with-caramel-sauce-in-glass-on-transparent-background-PNG.png";
                        break;

                    // French Category
                    case "French Fries":
                        options.Add("Extra Salt");
                        options.Add("Cheese Dip");
                        options.Add("Ketchup");
                        imagePath = "Images/cheeseburger.png";
                        break;
                    case "Croissant":
                        options.Add("Butter");
                        options.Add("Jam");
                        options.Add("Almonds");
                        imagePath = "Images/cheeseburger.png";
                        break;

                    // Drinks Category
                    case "Lemonade":
                        options.Add("Extra Lemon");
                        options.Add("Mint");
                        options.Add("Sugar-Free");
                        imagePath = "Images/cheeseburger.png";
                        break;
                    case "Iced Coffee":
                        options.Add("Almond Milk");
                        options.Add("Extra Ice");
                        options.Add("Whipped Cream");
                        imagePath = "Images/cheeseburger.png";
                        break;

                    // Chinese Category
                    case "Kung Pao Chicken":
                        options.Add("Extra Spicy");
                        options.Add("No Peanuts");
                        options.Add("Steamed Rice");
                        imagePath = "Images/cheeseburger.png";
                        break;
                    case "Sweet and Sour Pork":
                        options.Add("Extra Sauce");
                        options.Add("No Pineapple");
                        options.Add("Fried Rice");
                        imagePath = "Images/cheeseburger.png";
                        break;
                }

                try
                {
                    ProductImage.Source = new BitmapImage(new Uri(imagePath, UriKind.Absolute)); // Reemplazar con una URL válida
                }
                catch (Exception ex)
                {
                    MessageBox.Show("Error al cargar la imagen del producto: " + ex.Message);
                }

                // Agregar opciones dinámicas y aplicar selección previa (si existe)
                foreach (var option in options)
                {
                    var listBoxItem = CreateOptionItem(option);

                    // Verificar si esta opción fue previamente seleccionada
                    if (selectedOptions.ContainsKey(selectedProduct) && selectedOptions[selectedProduct].Contains(option))
                    {
                        listBoxItem.Background = Brushes.LightGreen; // Marcar como seleccionada
                    }

                    ProductOptions.Items.Add(listBoxItem);
                }

                // Actualizar la calificación promedio del producto seleccionado.
                UpdateAverageRating();
                ResetStars(); // Resetear las estrellas para el nuevo producto seleccionado.
                // Más productos se pueden agregar aquí...
            }
        }

        // Método que crea un ListBoxItem con el comportamiento de selección de color
        private StackPanel CreateOptionItem(string optionName)
        {
            var stackPanel = new StackPanel { Orientation = Orientation.Horizontal, Margin = new Thickness(5) };
            var listBoxItem = new ListBoxItem();
            listBoxItem.Content = optionName;
            listBoxItem.Margin = new Thickness(5, 0, 10, 0);

            // ComboBox para seleccionar la cantidad
            var quantityComboBox = new ComboBox();
            for (int i = 1; i <= 5; i++)
            {
                quantityComboBox.Items.Add(i);
            }
            quantityComboBox.SelectedIndex = 0; // Cantidad por defecto 1
            quantityComboBox.Margin = new Thickness(10, 0, 0, 0);

            // Manejar el evento de clic para cambiar el color
            listBoxItem.MouseLeftButtonUp += (s, e) =>
            {
                if (listBoxItem.Background == Brushes.LightGreen)
                {
                    listBoxItem.Background = Brushes.Transparent; // Deseleccionado
                    RemoveSelectedOption(optionName); // Remover opción seleccionada
                }
                else
                {
                    listBoxItem.Background = Brushes.LightGreen; // Seleccionado
                    AddSelectedOption(optionName, (int)quantityComboBox.SelectedItem); // Agregar opción seleccionada con la cantidad
                }
            };

            // Agregar el ListBoxItem y ComboBox al StackPanel
            stackPanel.Children.Add(listBoxItem);
            stackPanel.Children.Add(quantityComboBox);

            return stackPanel;
        }

        // Agregar una opción seleccionada al diccionario
        private void AddSelectedOption(string option, int quantity)
        {
            if (!selectedOptions.ContainsKey(selectedProduct))
            {
                selectedOptions[selectedProduct] = new List<string>();
            }
            selectedOptions[selectedProduct].Add($"{option} x{quantity}"); // Almacenar la opción con la cantidad
        }

        // Remover una opción seleccionada del diccionario
        private void RemoveSelectedOption(string option)
        {
            if (selectedOptions.ContainsKey(selectedProduct))
            {
                selectedOptions[selectedProduct].Remove(option);
            }
        }

        // Evento para calificar el producto
        private void Rate_Click(object sender, RoutedEventArgs e)
        {
            if (selectedProduct != null)
            {
                var button = sender as Button;
                int rating = int.Parse(button.Tag.ToString()); // Obtenemos el número de estrellas seleccionadas.

                
                // Si el producto no tiene calificaciones previas, inicializamos la lista.
                if (!productRatings.ContainsKey(selectedProduct))
                {
                    productRatings[selectedProduct] = new List<int>();
                }

                // Añadimos la nueva calificación al producto seleccionado.
                productRatings[selectedProduct].Add(rating);

                // Actualizamos visualmente las estrellas y el promedio.
                UpdateStars(rating);
                UpdateAverageRating();
            }
            else
            {
                MessageBox.Show("Por favor, selecciona un producto antes de calificar.");
            }
        }

        // Evento para borrar la calificación del producto
        private void ClearRating_Click(object sender, RoutedEventArgs e)
        {
            if (selectedProduct != null && productRatings.ContainsKey(selectedProduct))
            {
                productRatings[selectedProduct].Clear(); // Borra todas las calificaciones del producto.
                UpdateAverageRating(); // Resetea el promedio.
                ResetStars(); // Resetea las estrellas visuales.
            }
        }

        // Actualizar las estrellas visualmente
        private void UpdateStars(int rating)
        {
           
            try
            {
                StarImage1.Source = new BitmapImage(new Uri(rating >= 1 ? fullStarUrl : emptyStarUrl, UriKind.Absolute));
                StarImage2.Source = new BitmapImage(new Uri(rating >= 2 ? fullStarUrl : emptyStarUrl, UriKind.Absolute));
                StarImage3.Source = new BitmapImage(new Uri(rating >= 3 ? fullStarUrl : emptyStarUrl, UriKind.Absolute));
                StarImage4.Source = new BitmapImage(new Uri(rating >= 4 ? fullStarUrl : emptyStarUrl, UriKind.Absolute));
                StarImage5.Source = new BitmapImage(new Uri(rating >= 5 ? fullStarUrl : emptyStarUrl, UriKind.Absolute));
            }
            catch (Exception ex)
            {
                MessageBox.Show("Error al cargar las imágenes de las estrellas: " + ex.Message);
            }
        }

        // Actualizar la calificación promedio
        private void UpdateAverageRating()
        {
            if (productRatings.ContainsKey(selectedProduct) && productRatings[selectedProduct].Count > 0)
            {
                List<int> ratings = productRatings[selectedProduct];
                double average = ratings.Average(); // Calcula el promedio de las calificaciones.
                AverageRatingText.Text = $"{average:F1} / 5.0 basado en {ratings.Count} calificación(es)";
            }
            else
            {
                AverageRatingText.Text = "Sin calificaciones aún."; // Manejo de caso donde no hay calificaciones.
            }
        }

        // Resetea las estrellas a la imagen vacía
        private void ResetStars()
        {
            try
            {
                StarImage1.Source = new BitmapImage(new Uri(emptyStarUrl, UriKind.Absolute));
                StarImage2.Source = new BitmapImage(new Uri(emptyStarUrl, UriKind.Absolute));
                StarImage3.Source = new BitmapImage(new Uri(emptyStarUrl, UriKind.Absolute));
                StarImage4.Source = new BitmapImage(new Uri(emptyStarUrl, UriKind.Absolute));
                StarImage5.Source = new BitmapImage(new Uri(emptyStarUrl, UriKind.Absolute));
            }
            catch (Exception ex)
            {
                MessageBox.Show("Error al resetear las estrellas: " + ex.Message);
            }
        }

        // Evento para mostrar el resumen de compra
        private void ShowSummary_Click(object sender, RoutedEventArgs e)
        {
            string summary = "Resumen de Compra:\n";
            foreach (var product in selectedOptions)
            {
                summary += $"- {product.Key}: {string.Join(", ", product.Value)}\n"; // Mostrar opciones con cantidad
            }

            MessageBox.Show(summary, "Resumen de Compra");
        }

        // Evento para mostrar el mapa en una ventana emergente
        private void ShowMap_Click(object sender, RoutedEventArgs e)
        {
            if (selectedProduct != null)
            {
                MapWindow mapWindow = new MapWindow(selectedProduct); // Pasamos el producto seleccionado a la ventana de mapa.
                mapWindow.Show();
            }
            else
            {
                MessageBox.Show("Por favor, selecciona un producto antes de mostrar el mapa.");
            }
        }

    }
}
