'
' This file has generic items needed by all OCP LOCK UML sequence diagrams
'
'
!if %not(%variable_exists("ocp_lock_inc"))
    !$ocp_lock_inc = %true()

    !$SYNC_COLOR = "#red"
    !$ASYNC_COLOR = "#green"
    !$BUFFER_ACTIVATION = "#lightblue"

    !$sync = "-[" + $SYNC_COLOR + "]>"
    !$return = "-[" + $SYNC_COLOR + "]->"
    !$async = "-[" + $ASYNC_COLOR + "]>>"
    !$sometimelater = "..."

    !unquoted procedure $self($who, $msg)
       $who $sync $who : $msg
       ||0||
    !endprocedure

    !unquoted procedure $sometimelater()
        ...
        ||0||
    !endprocedure

    autonumber 1 1  "<b>[000]"

    !pragma teoz true

    participant "Remote Key\nManagement Service" as rkms
    participant "Host" as host
    participant "Storage\nDevice\nFW" as fw

    box "Caliptra"
        participant "Mail Box" as mb
        participant "ROM" as crom
        participant "FW" as cfw
        participant "ROM to FW\nHandoff Data" as hoff
        participant "DRBG" as rand
        participant "DMA Engine" as dma
        participant "Key Vault" as kv
        participant "Key Vault\nFuses" as fuses
        participant "Key Vault\nHEK" as ghek
        participant "Key Vault\nSlot A\n(HEK)" as hek
        participant "Key Vault\nSlot B\n(Ready MPK Encryption Key)" as mpks
        participant "Key Vault\nSlot F\n(DICE Alias Key)\necdsa_secp384r1_sha384" as dice
        participant "Key Vault\nSlot G\n(KEM Keypair)" as kemg
        participant "Key Vault\nSlot W\n(Temporary)" as tempw
        participant "Key Vault\nSlot X\n(MEK Secret Seed)" as meks
        participant "Key Vault\nSlot Y\n(Temporary)" as tempy
        participant "Key Vault\nSlot Z\n(Temporary)" as tempz
        participant "Key Vault\nTemp Memory" as tempmem
    end box

    box "Encryption engine"
        participant "SFR\nInterface" as sfr
        participant "Control" as ee
        participant "Key cache" as kc
    end box

    box "Media"
        participant "Create new HEK\non NVM subsystem reset" as chek
        participant "Destroy all HEK\non NVM subsystem reset" as dhek
    end box

    hide unlinked
!endif

