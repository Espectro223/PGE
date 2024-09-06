// FormMainMenu.cs
using System;
using System.Windows.Forms;

namespace VeterinariaSimulador
{
    public partial class FormMainMenu : Form
    {
        private Label lblBienvenida;
        private Button btnJugar;
        private Button btnTienda;
        private Button btnSalir;
        private string VeterinarioNombre;

        private int puntajeMaximo = 0;
        private int monedas = 0;

        public FormMainMenu(string nombreVeterinario)
        {
            InitializeComponent();
            VeterinarioNombre = nombreVeterinario;
            lblBienvenida.Text = $"¡Bienvenido Dr(a). {VeterinarioNombre}!";
        }

        private void InitializeComponent()
        {
            this.lblBienvenida = new Label();
            this.btnJugar = new Button();
            this.btnTienda = new Button();
            this.btnSalir = new Button();
            this.SuspendLayout();

            // lblBienvenida
            this.lblBienvenida.AutoSize = true;
            this.lblBienvenida.Location = new System.Drawing.Point(50, 30);
            this.lblBienvenida.Size = new System.Drawing.Size(200, 20);

            // btnJugar
            this.btnJugar.Location = new System.Drawing.Point(50, 70);
            this.btnJugar.Size = new System.Drawing.Size(150, 40);
            this.btnJugar.Text = "Jugar";
            this.btnJugar.Click += new EventHandler(this.btnJugar_Click);

            // btnTienda
            this.btnTienda.Location = new System.Drawing.Point(50, 120);
            this.btnTienda.Size = new System.Drawing.Size(150, 40);
            this.btnTienda.Text = "Tienda";

            // btnSalir
            this.btnSalir.Location = new System.Drawing.Point(50, 170);
            this.btnSalir.Size = new System.Drawing.Size(150, 40);
            this.btnSalir.Text = "Salir";
            this.btnSalir.Click += new EventHandler(this.btnSalir_Click);

            // FormMainMenu
            this.ClientSize = new System.Drawing.Size(300, 250);
            this.Controls.Add(this.lblBienvenida);
            this.Controls.Add(this.btnJugar);
            this.Controls.Add(this.btnTienda);
            this.Controls.Add(this.btnSalir);
            this.Text = "Menú Principal";
            this.ResumeLayout(false);
        }

        private void btnJugar_Click(object sender, EventArgs e)
        {
            this.Hide();
            FormVeterinaria formVeterinaria = new FormVeterinaria(VeterinarioNombre, this);
            formVeterinaria.Show();
        }

        private void btnTienda_Click(object sender, EventArgs e)
        {
            MessageBox.Show($"Tienes {monedas} monedas. (Tienda no implementada aún)");
        }

        private void btnSalir_Click(object sender, EventArgs e)
        {
            Application.Exit();
        }

        public void ActualizarPuntaje(int puntaje, int monedas)
        {
            this.puntajeMaximo = puntaje;
            this.monedas = monedas;
        }

        public void VolverAMenu()
        {
            this.Show();
        }
    }
}
