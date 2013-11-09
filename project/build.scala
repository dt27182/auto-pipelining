import sbt._
import Keys._
//val extracted: Extracted = Project.extract(state)
//import extracted._

object BuildSettings extends Build {
  val buildOrganization = "berkeley"
  val buildVersion = "1.0"
  val buildScalaVersion = "2.10.2"

  val buildSettings = Defaults.defaultSettings ++ Seq (
    //unmanagedBase <<= baseDirectory { base => base / ".." / custom_lib" },
    organization := buildOrganization,
    version      := buildVersion,
    scalaVersion := buildScalaVersion,
    traceLevel   := 15,
    scalacOptions ++= Seq("-deprecation","-unchecked"),
    resolvers ++= Seq(
      "Sonatype Snapshots" at "http://oss.sonatype.org/content/repositories/snapshots",
      "Sonatype Releases" at "http://oss.sonatype.org/content/repositories/releases",
      "scct-github-repository" at "http://mtkopone.github.com/scct/maven-repo"
    )
  )

  lazy val chisel = Project("chisel", file("chisel"), settings = buildSettings)
  lazy val autopipe = Project("autopipe", file("."), settings = buildSettings) dependsOn(chisel)
  lazy val cpu = Project("cpu", file("example"), settings = buildSettings) dependsOn(chisel,autopipe)

}
