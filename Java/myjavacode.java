import org.bukkit.Bukkit;
import org.bukkit.ChatColor;
import org.bukkit.Color;
import org.bukkit.entity.Player;
import org.bukkit.event.EventHandler;
import org.bukkit.event.Listener;
import org.bukkit.event.player.PlayerJoinEvent;
import org.bukkit.event.player.PlayerQuitEvent;
import org.bukkit.plugin.java.JavaPlugin;

public final class JoinQuitMsg extends JavaPlugin implements Listener {

    @Override
    public void onEnable() {
        // Plugin startup logic
        Bukkit.getServer().getConsoleSender().sendMessage(ChatColor.GREEN + "[JoinQuitMsg] Inicializado");
        getServer().getPluginManager().registerEvents(this,this);
    }

    @Override
    public void onDisable() {
        // Plugin shutdown logic
        Bukkit.getServer().getConsoleSender().sendMessage(ChatColor.RED + "[JoinQuitMsg] Interrompido");
    }

    @EventHandler
    public void onPlayerJoin(PlayerJoinEvent event){
        Player p = event.getPlayer();
        event.setJoinMessage(ChatColor.YELLOW + p.getName() + ChatColor.GREEN + " Bem vindo á nossa Cidade!");
    }

    @EventHandler
    public void onPlayerQuit(PlayerQuitEvent event){
        Player p = event.getPlayer();
        event.setQuitMessage(ChatColor.YELLOW + p.getName() +ChatColor.RED + " abandonou a Cidade, até uma proxima!!");
    }
}
