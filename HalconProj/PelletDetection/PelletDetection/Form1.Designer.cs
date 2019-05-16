namespace PelletDetection
{
	partial class Form1
	{
		/// <summary>
		/// Required designer variable.
		/// </summary>
		private System.ComponentModel.IContainer components = null;

		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		/// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
		protected override void Dispose(bool disposing)
		{
			if (disposing && (components != null))
			{
				components.Dispose();
			}
			base.Dispose(disposing);
		}

		#region Windows Form Designer generated code

		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		private void InitializeComponent()
		{
			this.hWindowControl1 = new HalconDotNet.HWindowControl();
			this.button1 = new System.Windows.Forms.Button();
			this.SuspendLayout();
			// 
			// hWindowControl1
			// 
			this.hWindowControl1.BackColor = System.Drawing.Color.Black;
			this.hWindowControl1.BorderColor = System.Drawing.Color.Black;
			this.hWindowControl1.ImagePart = new System.Drawing.Rectangle(0, 0, 640, 480);
			this.hWindowControl1.Location = new System.Drawing.Point(12, 12);
			this.hWindowControl1.Name = "hWindowControl1";
			this.hWindowControl1.Size = new System.Drawing.Size(338, 262);
			this.hWindowControl1.TabIndex = 0;
			this.hWindowControl1.WindowSize = new System.Drawing.Size(338, 262);
			this.hWindowControl1.HMouseMove += new HalconDotNet.HMouseEventHandler(this.HWindowControl1_HMouseMove);
			// 
			// button1
			// 
			this.button1.Location = new System.Drawing.Point(483, 251);
			this.button1.Name = "button1";
			this.button1.Size = new System.Drawing.Size(75, 23);
			this.button1.TabIndex = 1;
			this.button1.Text = "button1";
			this.button1.UseVisualStyleBackColor = true;
			this.button1.Click += new System.EventHandler(this.Button1_Click);
			// 
			// Form1
			// 
			this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
			this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
			this.ClientSize = new System.Drawing.Size(800, 450);
			this.Controls.Add(this.button1);
			this.Controls.Add(this.hWindowControl1);
			this.Name = "Form1";
			this.Text = "Form1";
			this.ResumeLayout(false);

		}

		#endregion

		private HalconDotNet.HWindowControl hWindowControl1;
		private System.Windows.Forms.Button button1;
	}
}

