'use strict';
// The module 'vscode' contains the VS Code extensibility API
// Import the module and reference it with the alias vscode in your code below
import * as vscode from 'vscode';
import * as vscodelc from 'vscode-languageclient';

// this method is called when your extension is activated
// your extension is activated the very first time the command is executed
export function activate(context: vscode.ExtensionContext) {
    const lsId: string = 'advplLs';
    const lsServerOptions: vscodelc.Executable = {
        command: vscode.workspace.getConfiguration(lsId).get('bin')
    };
    const serverOptions: vscodelc.ServerOptions = lsServerOptions;
    const clientOptions: vscodelc.LanguageClientOptions = {
        documentSelector: [
            { "language": "advpl" }
        ]
    };
    const advplClient = new vscodelc.LanguageClient(lsId, 'AdvPL Language Server', serverOptions, clientOptions);
    const disposable = advplClient.start();

    context.subscriptions.push(disposable);
}

// this method is called when your extension is deactivated
export function deactivate() {
}
