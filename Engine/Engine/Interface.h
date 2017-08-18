#include "scene.h"
#include <string.h>
#include <stdio.h>
#pragma once

namespace Engine {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// —водка дл€ Interface
	/// </summary>
	public ref class Interface : public System::Windows::Forms::Form
	{
	public:
		Interface(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
		}

	protected:
		/// <summary>
		/// ќсвободить все используемые ресурсы.
		/// </summary>
		~Interface()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::TextBox^  textBox1;
	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::Button^  button2;
	private: System::Windows::Forms::Button^  button3;
	private: System::Windows::Forms::TableLayoutPanel^  tableLayoutPanel1;
	private: System::Windows::Forms::TableLayoutPanel^  tableLayoutPanel2;

	private: unsigned int global_scene_cnt;

	private: array<scene^>^ scenes;		
	private: unsigned int scene_cnter;

	private: array<String^>^ keyTexts;
	private: array<String^>^ splittedLine;

	protected: 

	private:
		/// <summary>
		/// “ребуетс€ переменна€ конструктора.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// ќб€зательный метод дл€ поддержки конструктора - не измен€йте
		/// содержимое данного метода при помощи редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->tableLayoutPanel1 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->tableLayoutPanel2 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->tableLayoutPanel1->SuspendLayout();
			this->tableLayoutPanel2->SuspendLayout();
			this->SuspendLayout();
			// 
			// textBox1
			// 
			this->textBox1->BackColor = System::Drawing::Color::DimGray;
			this->textBox1->Dock = System::Windows::Forms::DockStyle::Fill;
			this->textBox1->Location = System::Drawing::Point(3, 3);
			this->textBox1->Multiline = true;
			this->textBox1->Name = L"textBox1";
			this->textBox1->ScrollBars = System::Windows::Forms::ScrollBars::Vertical;
			this->textBox1->Size = System::Drawing::Size(523, 173);
			this->textBox1->TabIndex = 0;
			this->textBox1->TextChanged += gcnew System::EventHandler(this, &Interface::textBox1_TextChanged);
			// 
			// button1
			// 
			this->button1->Dock = System::Windows::Forms::DockStyle::Fill;
			this->button1->Location = System::Drawing::Point(3, 3);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(523, 23);
			this->button1->TabIndex = 1;
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &Interface::button1_Click);
			// 
			// button2
			// 
			this->button2->Dock = System::Windows::Forms::DockStyle::Fill;
			this->button2->Location = System::Drawing::Point(3, 32);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(523, 23);
			this->button2->TabIndex = 2;
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &Interface::button2_Click);
			// 
			// button3
			// 
			this->button3->Dock = System::Windows::Forms::DockStyle::Fill;
			this->button3->Location = System::Drawing::Point(3, 61);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(523, 23);
			this->button3->TabIndex = 3;
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &Interface::button3_Click);
			// 
			// tableLayoutPanel1
			// 
			this->tableLayoutPanel1->ColumnCount = 1;
			this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,100)));
			this->tableLayoutPanel1->Controls->Add(this->button3, 0, 2);
			this->tableLayoutPanel1->Controls->Add(this->button1, 0, 0);
			this->tableLayoutPanel1->Controls->Add(this->button2, 0, 1);
			this->tableLayoutPanel1->Dock = System::Windows::Forms::DockStyle::Bottom;
			this->tableLayoutPanel1->Location = System::Drawing::Point(0, 182);
			this->tableLayoutPanel1->Name = L"tableLayoutPanel1";
			this->tableLayoutPanel1->RowCount = 3;
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 33.33333F)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 33.33333F)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 33.33333F)));
			this->tableLayoutPanel1->Size = System::Drawing::Size(529, 87);
			this->tableLayoutPanel1->TabIndex = 4;
			// 
			// tableLayoutPanel2
			// 
			this->tableLayoutPanel2->ColumnCount = 1;
			this->tableLayoutPanel2->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 
				50)));
			this->tableLayoutPanel2->Controls->Add(this->textBox1, 0, 0);
			this->tableLayoutPanel2->Dock = System::Windows::Forms::DockStyle::Top;
			this->tableLayoutPanel2->Location = System::Drawing::Point(0, 0);
			this->tableLayoutPanel2->Name = L"tableLayoutPanel2";
			this->tableLayoutPanel2->RowCount = 1;
			this->tableLayoutPanel2->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 50)));
			this->tableLayoutPanel2->Size = System::Drawing::Size(529, 179);
			this->tableLayoutPanel2->TabIndex = 5;
			// 
			// Interface
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::White;
			this->ClientSize = System::Drawing::Size(529, 269);
			this->Controls->Add(this->tableLayoutPanel2);
			this->Controls->Add(this->tableLayoutPanel1);
			this->Name = L"Interface";
			this->Text = L"Interface";
			this->Load += gcnew System::EventHandler(this, &Interface::Interface_Load);
			this->tableLayoutPanel1->ResumeLayout(false);
			this->tableLayoutPanel2->ResumeLayout(false);
			this->tableLayoutPanel2->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion

	private: System::Void textBox1_TextChanged(System::Object^  sender, System::EventArgs^  e) {
			 }

	private: void initial()
			 {
				 /*
				 System::IO::File::ReadLines(fname+"relations.txt");
				 confFile=fname->Split(L'$');*/

				 FILE *stream;
				 char msg[] = "this is a test";
				 char buf[20];

				 if ((stream = fopen("Texts\\Scene_relations.txt", "r"))== NULL)
				 {
					 System::Windows::Forms::MessageBox::Show("Cannot open file.\n");
					 this->Close();
				 }

				 fseek(stream, SEEK_SET, 0);
				 fgets(buf,20,stream);
				 //fread(buf, 1, 20, stream);
				 //System::Windows::Forms::MessageBox::Show(gcnew String(buf)/*System::Convert::ToString(buf)*/);

				 //fclose(stream);
				 //return 0;


				 this->global_scene_cnt=0;
				 this->scene_cnter=System::Convert::ToInt32(gcnew String(buf));
				 this->scenes= gcnew array<scene^>(this->scene_cnter);
				 String^ fname =System::Convert::ToString("Texts\\Scene_");
				 String^ audname =System::Convert::ToString("Sounds\\Sound_");
				 String^ kname =System::Convert::ToString("Texts\\Text_for_buttons\\Text_");
				 for (int i=0;i<scene_cnter;i++)
				 {
					 if((System::IO::File::Exists(audname+i+".wav"))&&(System::IO::File::Exists(kname+i+".txt"))&&(System::IO::File::Exists(kname+i+".txt")))
					 {
						 this->scenes[i]= gcnew scene(System::IO::File::ReadAllText(fname+i+".txt"),
							 audname+i+".wav", gcnew array<int>{-1,-1,-1}, System::IO::File::ReadAllText(kname+i+".txt"));
					 }
					 else
					 {
						 this->scenes[i]= gcnew scene(System::IO::File::ReadAllText(fname+"default.txt"),
							 audname+"default.wav", gcnew array<int>{0,-1,-1}, System::IO::File::ReadAllText(kname+"default.txt"));
					 }

					 fgets(buf,20,stream);
					 String^ line= gcnew String(buf);
					 splittedLine=line->Split(L' ');
					 scenes[i]->keys=gcnew array<int>{System::Convert::ToInt32(splittedLine[0]),System::Convert::ToInt32(splittedLine[1]),System::Convert::ToInt32(splittedLine[2])};

				 }
				 fclose(stream);
			 }
	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) 
			 {
				 repaint(0);
			 }
	private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) 
			 {
				 repaint(1);
			 }
	private: System::Void button3_Click(System::Object^  sender, System::EventArgs^  e) 
			 {
				 repaint(2);
			 }
	private: System::Void repaint(int c)
			 {
				 if(c==-1)
				 {
					 global_scene_cnt=0;
				 }
				 else if (scenes[global_scene_cnt]->keys[c]!=-1)
				 {
					 global_scene_cnt=scenes[global_scene_cnt]->keys[c];
				 }

				 this->textBox1->Text=scenes[global_scene_cnt]->text;

				 System::Media::SoundPlayer player;

				 player.SoundLocation=scenes[global_scene_cnt]->music;
				 player.Play();

				 keyTexts= scenes[global_scene_cnt]->keys_name->Split(L'$');
				 this->button1->Text= keyTexts[0];

				 this->button2->Text="";
				 this->button3->Text="";
				 button2->Enabled=true;
				 button3->Enabled=true;
				 if (keyTexts->Length>1)
				 {
					 this->button2->Text= keyTexts[1];
					 if(keyTexts->Length>2)
					 {
						 this->button3->Text= keyTexts[2];
					 }
					 else button3->Enabled=false;
				 }
				 else 
				 {
					 button2->Enabled=false;
					 button3->Enabled=false;
				 }

			 }
	private: System::Void Interface_Load(System::Object^  sender, System::EventArgs^  e) 
			 {
				 initial();
				 repaint(-1);
			 }
	};
}

