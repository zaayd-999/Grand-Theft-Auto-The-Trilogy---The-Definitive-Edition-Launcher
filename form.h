#pragma once

namespace GTALAUNCHER {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Media;
	using namespace System::Diagnostics;
	using namespace System;
	using namespace System::IO;
	using namespace System::Windows::Forms;

	/// <summary>
	/// Summary for main
	/// </summary>
	public ref class main : public System::Windows::Forms::Form
	{
	public:
		main(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~main()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::PictureBox^ GTA_VC_pic;
	private: System::Windows::Forms::PictureBox^ GTA_3_pic;
	private: System::Windows::Forms::PictureBox^ GTA_SA_pic;
	private: System::Windows::Forms::PictureBox^ Play_btn;
	private: int selected;
	private: SoundPlayer^ player;
	private: String^ configPath = "./Resources/config.ini";
	private: String^ GTA3path;
	private: String^ GTAVCpath;
	private: String^ GTASApath;
	protected:

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(main::typeid));
			this->GTA_VC_pic = (gcnew System::Windows::Forms::PictureBox());
			this->GTA_3_pic = (gcnew System::Windows::Forms::PictureBox());
			this->GTA_SA_pic = (gcnew System::Windows::Forms::PictureBox());
			this->Play_btn = (gcnew System::Windows::Forms::PictureBox());
			this->selected = -1;
			this->SuspendLayout();
			// 
			// GTA VC
			// 
			this->GTA_VC_pic->Image = Image::FromFile("./Resources/images/vc.jpg");
			this->GTA_VC_pic->Location = System::Drawing::Point(0, 61);
			this->GTA_VC_pic->Name = L"GTA VICE CITY";
			this->GTA_VC_pic->SizeMode = PictureBoxSizeMode::StretchImage;
			this->GTA_VC_pic->Size = System::Drawing::Size(330, 640);
			this->GTA_VC_pic->TabIndex = 0;
			this->GTA_VC_pic->TabStop = false;
			// 
			// GTA 3
			// 
			this->GTA_3_pic->Image = Image::FromFile("./Resources/images/3.jpg");
			this->GTA_3_pic->Location = System::Drawing::Point(350, 60);
			this->GTA_3_pic->Name = L"GTA 3";
			this->GTA_3_pic->SizeMode = PictureBoxSizeMode::StretchImage;
			this->GTA_3_pic->Size = System::Drawing::Size(330, 642);
			this->GTA_3_pic->TabIndex = 0;
			this->GTA_3_pic->TabStop = false;
			// 
			// GTA SA
			// 
			this->GTA_SA_pic->Image = Image::FromFile("./Resources/images/sa.jpg");
			this->GTA_SA_pic->Location = System::Drawing::Point(699, 60);
			this->GTA_SA_pic->Name = L"GTA SA";
			this->GTA_SA_pic->SizeMode = PictureBoxSizeMode::StretchImage;
			this->GTA_SA_pic->Size = System::Drawing::Size(330, 642);
			this->GTA_SA_pic->TabIndex = 0;
			this->GTA_SA_pic->TabStop = false;
			// 
			// main
			// 
			this->BackgroundImage = Image::FromFile("./Resources/images/background.png");
			this->BackgroundImageLayout = ImageLayout::Stretch;
			this->AutoScaleDimensions = System::Drawing::SizeF(9, 20);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1028, 726);
			this->Controls->Add(this->GTA_VC_pic);
			this->Controls->Add(this->GTA_3_pic);
			this->Controls->Add(this->GTA_SA_pic);
			this->Controls->Add(this->Play_btn);
			this->ForeColor = System::Drawing::SystemColors::ControlText;
			this->MaximizeBox = false;
			this->MinimizeBox = false;
			this->Name = L"main";
			this->Text = L"Grand Theft Auto: The Trilogy - The Definitive Edition Launcher";
			this->Icon = gcnew System::Drawing::Icon("./Resources/icon/app_logo.ico");
			//
			// Play Btn
			// 
			this->Play_btn->Image = Image::FromFile("./Resources/images/play_btn.png");
			this->Play_btn->Location = System::Drawing::Point(800, 0);
			this->Play_btn->Name = L"Play btn";
			//this->Play_btn->SizeMode = PictureBoxSizeMode::StretchImage;
			this->Play_btn->Size = System::Drawing::Size(300, 60);
			this->Play_btn->TabIndex = 0;
			this->Play_btn->TabStop = false;
			this->Load += gcnew System::EventHandler(this, &main::main_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->GTA_VC_pic))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->GTA_3_pic))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->GTA_SA_pic))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->Play_btn))->EndInit();
			this->GTA_VC_pic->MouseClick += gcnew MouseEventHandler(this, &main::OnImageClick);
			this->GTA_3_pic->MouseClick += gcnew MouseEventHandler(this, &main::OnImageClick);
			this->GTA_SA_pic->MouseClick += gcnew MouseEventHandler(this, &main::OnImageClick);
			this->Play_btn->MouseClick += gcnew MouseEventHandler(this, &main::OnImageClick);
			this->MouseClick += gcnew MouseEventHandler(this, &main::main_ClientMouseClick);
			this->ResumeLayout(false);

		}
#pragma endregion

	private: System::Void main_ClientMouseClick(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
		System::Windows::Forms::Control^ clickedControl = this->GetChildAtPoint(Point(e->X, e->Y));
		if (clickedControl == nullptr) {
			this->player->Stop();
			this->player = (gcnew SoundPlayer("./Resources/sound/default.wav"));
			this->player->Load();
			this->player->PlayLooping();
			this->selected = -1;
			this->GTA_SA_pic->Image = Image::FromFile("./Resources/images/sa.jpg");
			this->GTA_VC_pic->Image = Image::FromFile("./Resources/images/vc.jpg");
			this->GTA_3_pic->Image = Image::FromFile("./Resources/images/3.jpg");

		}
		else if (clickedControl != GTA_VC_pic &&
			clickedControl != GTA_3_pic &&
			clickedControl != GTA_SA_pic && clickedControl != Play_btn) {
			this->player->Stop();
			this->player = (gcnew SoundPlayer("./Resources/sound/default.wav"));
			this->player->Load();
			this->player->PlayLooping();
			this->selected = -1;
			this->GTA_SA_pic->Image = Image::FromFile("./Resources/images/sa.jpg");
			this->GTA_VC_pic->Image = Image::FromFile("./Resources/images/vc.jpg");
			this->GTA_3_pic->Image = Image::FromFile("./Resources/images/3.jpg");
		}
	}
	private: System::Void main_Load(System::Object^ sender, System::EventArgs^ e) {
		this->selected = -1;
		this->player = (gcnew SoundPlayer("./Resources/sound/default.wav"));
		this->player->Load();
		this->player->PlayLooping();
	}
	private: System::Void OnImageClick(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
		PictureBox^ clickedPic = safe_cast<PictureBox^>(sender);
		if (clickedPic == GTA_VC_pic) {
			this->GTA_SA_pic->Image = Image::FromFile("./Resources/images/sa_d.png");
			this->GTA_3_pic->Image = Image::FromFile("./Resources/images/3_d.png");
			this->GTA_VC_pic->Image = Image::FromFile("./Resources/images/vc.jpg");
			this->selected = 0;
			this->player->Stop();
			this->player = (gcnew SoundPlayer("./Resources/sound/vc.wav"));
			this->player->Load();
			this->player->PlayLooping();
		}
		else if (clickedPic == GTA_3_pic) {
			this->GTA_SA_pic->Image = Image::FromFile("./Resources/images/sa_d.png");
			this->GTA_3_pic->Image = Image::FromFile("./Resources/images/3.jpg");
			this->GTA_VC_pic->Image = Image::FromFile("./Resources/images/vc_d.png");
			this->selected = 1;
			this->player->Stop();
			this->player = (gcnew SoundPlayer("./Resources/sound/3.wav"));
			this->player->Load();
			this->player->PlayLooping();
		}
		else if (clickedPic == GTA_SA_pic) {
			this->GTA_SA_pic->Image = Image::FromFile("./Resources/images/sa.jpg");
			this->GTA_3_pic->Image = Image::FromFile("./Resources/images/3_d.png");
			this->GTA_VC_pic->Image = Image::FromFile("./Resources/images/vc_d.png");
			this->selected = 2;
			this->player->Stop();
			this->player = (gcnew SoundPlayer("./Resources/sound/sa.wav"));
			this->player->Load();
			this->player->PlayLooping();
		}
		else if (clickedPic == Play_btn) {
			if (this->selected == -1) {
				MessageBox::Show("Please Select a game to start.");
			} else {
				try {
					if (File::Exists(configPath)) {
						//MessageBox::Show("File exists");
						StreamReader^ reader = gcnew StreamReader(configPath);
						String^ line = "";
						while ((line = reader->ReadLine()) != nullptr) {
							if (!String::IsNullOrWhiteSpace(line) && line->Contains("=")) {
								array<String^>^ parts = line->Split('=');  // split at '='
								String^ key = parts[0]->Trim();
								String^ value = parts[1]->Trim();
								//MessageBox::Show("Key: " + key + "\nValue: " + value, "Configuration");
								if (key == "GTASA") GTASApath = value;
								if (key == "GTAVC") GTAVCpath = value;
								if (key == "GTA3") GTA3path = value;
							}
						}
						reader->Close();
						String^ path = "";
						if (this->selected == 0) {
							MessageBox::Show("Launching GTAVC.exe");
							path = GTAVCpath;
						} else if (this->selected == 1) {
							MessageBox::Show("Launching GTA3.exe");
							path = GTA3path;
						}
						else if (this->selected == 2) {
							MessageBox::Show("Launching GTASA.exe");
							path = GTASApath;
						}
						try {
							Process::Start(path);
							this->player->Stop();
							this->selected = -1;
							this->GTA_SA_pic->Image = Image::FromFile("./Resources/images/sa.jpg");
							this->GTA_VC_pic->Image = Image::FromFile("./Resources/images/vc.jpg");
							this->GTA_3_pic->Image = Image::FromFile("./Resources/images/3.jpg");
						} catch ( Exception^ ex) {
							MessageBox::Show("Error launching file: " + ex->Message);
						}
						
					}
				}
				catch (Exception^ ex) {
					MessageBox::Show("Error reading file: " + ex->Message);
				}
			}
		}
	}
	};
}
