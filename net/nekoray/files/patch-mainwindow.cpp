--- ui/mainwindow.cpp.orig	2024-12-12 11:03:36.000000000 +0300
+++ ui/mainwindow.cpp	2025-07-15 10:20:38.093780000 +0300
@@ -252,7 +252,7 @@
     //
     connect(ui->menu_program, &QMenu::aboutToShow, this, [=]() {
         ui->actionRemember_last_proxy->setChecked(NekoGui::dataStore->remember_enable);
-        ui->actionStart_with_system->setChecked(AutoRun_IsEnabled());
+//        ui->actionStart_with_system->setChecked(AutoRun_IsEnabled());
         ui->actionAllow_LAN->setChecked(QStringList{"::", "0.0.0.0"}.contains(NekoGui::dataStore->inbound_address));
         // active server
         for (const auto &old: ui->menuActive_Server->actions()) {
@@ -313,7 +313,7 @@
         NekoGui::dataStore->Save();
     });
     connect(ui->actionStart_with_system, &QAction::triggered, this, [=](bool checked) {
-        AutoRun_SetEnabled(checked);
+ //       AutoRun_SetEnabled(checked);
     });
     connect(ui->actionAllow_LAN, &QAction::triggered, this, [=](bool checked) {
         NekoGui::dataStore->inbound_address = checked ? "::" : "127.0.0.1";
