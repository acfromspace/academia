import org.eclipse.jface.dialogs.MessageDialog;
import org.eclipse.swt.widgets.Display;
import org.eclipse.swt.widgets.Shell;
import org.eclipse.swt.widgets.Text;
import org.eclipse.swt.SWT;
import org.eclipse.swt.widgets.Label;
import org.eclipse.swt.widgets.Button;
import org.eclipse.swt.events.SelectionAdapter;
import org.eclipse.swt.events.SelectionEvent;
import org.eclipse.wb.swt.SWTResourceManager;


public class CelFar {

	protected Shell shell;
	private Text input1;
	private Text input2;

	/**
	 * Launch the application.
	 * @param args
	 */
	public static void main(String[] args) {
		try {
			CelFar window = new CelFar();
			window.open();
		} catch (Exception e) {
			e.printStackTrace();
		}
	}

	/**
	 * Open the window.
	 */
	public void open() {
		Display display = Display.getDefault();
		createContents();
		shell.open();
		shell.layout();
		while (!shell.isDisposed()) {
			if (!display.readAndDispatch()) {
				display.sleep();
			}
		}
	}

	/**
	 * Create contents of the window.
	 */
	protected void createContents() {
		shell = new Shell();
		shell.setSize(450, 300);
		shell.setText("Simple F/C Converter");
		
		input1 = new Text(shell, SWT.BORDER);
		input1.setBounds(37, 43, 99, 21);
		
		input2 = new Text(shell, SWT.BORDER);
		input2.setBounds(37, 115, 99, 21);
		
		Label label1 = new Label(shell, SWT.NONE);
		label1.setBounds(37, 22, 70, 15);
		label1.setText("Fahrenheit");
		
		Label label2 = new Label(shell, SWT.NONE);
		label2.setBounds(37, 94, 55, 15);
		label2.setText("Celsius");
		
		final Label answerLabel = new Label(shell, SWT.NONE);
		answerLabel.setFont(SWTResourceManager.getFont("Segoe UI", 10, SWT.BOLD));
		answerLabel.setBounds(37, 175, 368, 64);
		answerLabel.setText("(Conversion answer here.)");
		
		Button option1 = new Button(shell, SWT.NONE);
		option1.addSelectionListener(new SelectionAdapter() {
			@Override
			public void widgetSelected(SelectionEvent e) {
				int numberF;
				try {
					numberF = Integer.parseInt(input1.getText());
				}
				catch (Exception exc)
				{
					MessageDialog.openError(shell,"Error","bad number");
					return;
				}
				int convertF = (numberF - 32) * 5/9;
				answerLabel.setText("The conversion from F\u00B0 to C\u00B0 is " + convertF);
			}
		});
		option1.setToolTipText("Convert F\u00B0 to C\u00B0");
		option1.setBounds(161, 41, 99, 25);
		option1.setText("Convert F\u00B0 to C\u00B0");
		
		Button option2 = new Button(shell, SWT.NONE);
		option2.addSelectionListener(new SelectionAdapter() {
			@Override
			public void widgetSelected(SelectionEvent e) {
				int numberC;
				try {
					numberC = Integer.parseInt(input2.getText());
				}
				catch (Exception exc)
				{
					MessageDialog.openError(shell,"Error","bad number");
					return;
				}
				int convertC = numberC * 9/5 + 32;
				answerLabel.setText("The conversion from C\u00B0 to F\u00B0 is " + convertC);
			}
		});
		option2.setToolTipText("Convert C\u00B0 to F\u00B0");
		option2.setBounds(161, 113, 99, 25);
		option2.setText("Convert C\u00B0 to F\u00B0");
	}
}
