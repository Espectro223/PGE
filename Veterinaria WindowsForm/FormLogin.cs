// FormLogin.cs
using System;
using System.Windows.Forms;

namespace VeterinariaSimulador
{
    public partial class FormLogin : Form
    {
        private Label lblNombre;
        private TextBox txtNombre;
        private Button btnIniciar;

        public string VeterinarioNombre { get; private set; }

        public FormLogin()
        {
            InitializeComponent();
        }

        private void InitializeComponent()
        {
            this.lblNombre = new Label();
            this.txtNombre = new TextBox();
            this.btnIniciar = new Button();
            this.SuspendLayout();

            // lblNombre
            this.lblNombre.AutoSize = true;
            this.lblNombre.Location = new System.Drawing.Point(30, 30);
            this.lblNombre.Name = "lblNombre";
            this.lblNombre.Size = new System.Drawing.Size(120, 20);
            this.lblNombre.Text = "Nombre del Veterinario:";

            // txtNombre
            this.txtNombre.Location = new System.Drawing.Point(30, 60);
            this.txtNombre.Size = new System.Drawing.Size(200, 26);

            // btnIniciar
            this.btnIniciar.Location = new System.Drawing.Point(30, 100);
            this.btnIniciar.Size = new System.Drawing.Size(100, 30);
            this.btnIniciar.Text = "Iniciar";
            this.btnIniciar.Click += new EventHandler(this.btnIniciar_Click);

            // FormLogin
            this.ClientSize = new System.Drawing.Size(300, 200);
            this.Controls.Add(this.lblNombre);
            this.Controls.Add(this.txtNombre);
            this.Controls.Add(this.btnIniciar);
            this.Text = "Iniciar Sesión";
            this.ResumeLayout(false);
        }

        private void btnIniciar_Click(object sender, EventArgs e)
        {
            VeterinarioNombre = txtNombre.Text;
            if (!string.IsNullOrEmpty(VeterinarioNombre))
            {
                this.Hide();
                FormMainMenu mainMenu = new FormMainMenu(VeterinarioNombre);
                mainMenu.Show();
            }
            else
            {
                MessageBox.Show("Por favor, ingrese su nombre.");
            }
        }
    }
}
